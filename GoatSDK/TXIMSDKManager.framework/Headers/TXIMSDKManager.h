//
//  TXIMSDKManager.h
//  TXIMSDKManager
//
//  Created by Adminstration on 2021/6/11.
//

#import <Foundation/Foundation.h>
#import <ImSDK_Plus/ImSDK_Plus.h>
#import "GIMSender.h"
#import "GIMReceiver.h"


NS_ASSUME_NONNULL_BEGIN

@interface TXIMSDKManager : NSObject

/**
 *  1.1 获取 TXIMSDKManager 管理器实例
 */

+ (instancetype)sharedInstance;
/**
 *  1.2 初始化 SDK
 *
 *  @param sdkAppID 应用 ID，必填项，可以在 [控制台](https://console.cloud.tencent.com/im) 中获取
 *  @param gameID 游戏ID
 *  @param production 是否是正式环境
 *  @param config 配置信息
 *  @return YES：成功；NO：失败
 */

- (BOOL)initsdkAppID:(int)sdkAppID gameID:(NSString *)gameID production:(BOOL)production config:(V2TIMSDKConfig*)config listener:(id<V2TIMSDKListener>)listener;

/**
 *  1.3 反初始化 SDK
 */
- (void)unInitSDK;

/**
 *  1.4 获取版本号
 *
 *  @return 返回版本号，字符串表示，例如 5.0.10
 */
- (NSString*)getVersion;

/**
 *  1.5 获取服务器当前时间
 *
 *  可用于信令离线推送场景下超时判断。
 *
 *  示例代码请参考 TUIKit：
 *  信令邀请方：TUICall+Signal.m -> getOfflinePushInfo 设置邀请的服务器时间 serverTime 。
 *  信令接收方：AppDelegate.m -> didReceiveRemoteNotification，收到信令推送，根据 serverTime 判断信令是否超时 。
 *
 *  @return 服务器时间，单位 s
 */
- (uint64_t)getServerTime;

/////////////////////////////////////////////////////////////////////////////////
//                               登录登出
/////////////////////////////////////////////////////////////////////////////////

/**
 *  2.1 登录
 *
 *  登录需要设置用户名 userID 和用户签名 userSig，userSig 生成请参考 [UserSig 后台 API](https://cloud.tencent.com/document/product/269/32688)。
 *
 *  @note 请注意如下特殊逻辑:
 * - 登陆时票据过期：login 函数的 V2TIMFail 会返回 ERR_USER_SIG_EXPIRED：6206 错误码，此时生成新的 userSig 重新登录。
 * - 在线时票据过期：用户在线期间也可能收到 V2TIMSDKListener -> onUserSigExpired 回调，此时也是需要您生成新的 userSig 并重新登录。
 * - 在线时被踢下线：用户在线情况下被踢，SDK 会通过 V2TIMSDKListener -> onKickedOffline 回调通知给您，此时可以 UI 提示用户，并再次调用 login() 重新登录。
 */
- (void)loginWithUserSig:(NSString *)userSig  token:(NSString *)token sender:(GIMSender *)sender succ:(V2TIMSucc)succ fail:(V2TIMFail)fail;

/**
 *  2.2 登出
 *
 *  退出登录，如果切换账号，需要 logout 回调成功或者失败后才能再次 login，否则 login 可能会失败。
 */
- (void)logout:(V2TIMSucc)succ fail:(V2TIMFail)fail;

/**
 *  2.3 获取登录用户
 */
- (NSString *)getLoginUser;

/**
 *  2.4 获取登录状态
 *
 *  如果用户已经处于已登录和登录中状态，请勿再频繁调用登录接口登录。
 */
- (V2TIMLoginStatus)getLoginStatus;

/////////////////////////////////////////////////////////////////////////////////
//                         消息收发
/////////////////////////////////////////////////////////////////////////////////

/**
 *  3.1 设置基本消息（文本消息和自定义消息）的事件监听器
 *
 *  @note 图片消息、视频消息、语音消息等高级消息的监听，请参考 V2TIMManager+Message.h -> addAdvancedMsgListener 接口。
 */
- (void)addSimpleMsgListener:(id<V2TIMSimpleMsgListener>)listener NS_SWIFT_NAME(addSimpleMsgListener(listener:));

/**
 *  3.2 移除基本消息（文本消息和自定义消息）的事件监听器
 */
- (void)removeSimpleMsgListener:(id<V2TIMSimpleMsgListener>)listener NS_SWIFT_NAME(removeSimpleMsgListener(listener:));

/**
 *  3.3 发送单聊普通文本消息（最大支持 8KB）
 *
 *  文本消息支持云端的脏词过滤，如果用户发送的消息中有敏感词，V2TIMFail 回调将会返回 80001 错误码。
 *  @return 返回消息的唯一标识 ID
 *
 *  @note 该接口发送的消息默认会推送（前提是在 V2TIMManager+APNS.h 开启了推送），如果需要自定义推送（自定义推送声音，推送 Title 等），请调用 V2TIMManager+Message.h -> sendMessage 接口。
 */
- (NSString*)sendC2CTextMessage:(NSString *)text to:(NSString *)userID succ:(V2TIMSucc)succ fail:(V2TIMFail)fail;

/**
 *  3.4 发送单聊自定义（信令）消息（最大支持 8KB）
 *
 *  自定义消息本质就是一端二进制 buffer，您可以在其上自由组织自己的消息格式（常用于发送信令），但是自定义消息不支持云端敏感词过滤。
 *  @return 返回消息的唯一标识 ID
 *
 *  @note 该接口发送的消息默认不会推送，如果需要推送，请调用 V2TIMManager+Message.h -> sendMessage 接口。
 */
- (NSString*)sendC2CCustomMessage:(NSData *)customData to:(NSString *)userID succ:(V2TIMSucc)succ fail:(V2TIMFail)fail;

/**
 *  3.5 发送群聊普通文本消息（最大支持 8KB）
 *
 *  @param priority 设置消息的优先级，我们没有办法所有消息都能 100% 送达每一个用户，但高优先级的消息会有更高的送达成功率。
 *      - HIGH ：云端会优先传输，适用于在群里发送重要消息，比如主播发送的文本消息等。
 *      - NORMAL ：云端按默认优先级传输，适用于在群里发送普通消息，比如观众发送的弹幕消息等。
 *  @return 返回消息的唯一标识 ID
 *
 *  @note 该接口发送的消息默认会推送（前提是在 V2TIMManager+APNS.h 开启了推送），如果需要自定义推送（自定义推送声音，推送 Title 等），请调用 V2TIMManager+Message.h -> sendMessage 接口。
 */
- (NSString*)sendGroupTextMessage:(NSString *)text to:(NSString *)groupID priority:(V2TIMMessagePriority)priority succ:(V2TIMSucc)succ fail:(V2TIMFail)fail;

/**
 *  3.6 发送群聊自定义（信令）消息（最大支持 8KB）
 *
 *  @param priority 设置消息的优先级，我们没有办法所有消息都能 100% 送达每一个用户，但高优先级的消息会有更高的送达成功率。
 *      - HIGH ：云端会优先传输，适用于在群里发送重要信令，比如连麦邀请，PK邀请、礼物赠送等关键性信令。
 *      - NORMAL ：云端按默认优先级传输，适用于在群里发送非重要信令，比如观众的点赞提醒等等。
 *  @return 返回消息的唯一标识 ID
 *
 *  @note 该接口发送的消息默认不会推送，如果需要推送，请调用 V2TIMManager+Message.h -> sendMessage 接口。
 */
- (NSString*)sendGroupCustomMessage:(NSData *)customData to:(NSString *)groupID priority:(V2TIMMessagePriority)priority succ:(V2TIMSucc)succ fail:(V2TIMFail)fail;

//  3.7 更多功能，详见 V2TIMManager+Message.h

/////////////////////////////////////////////////////////////////////////////////
//                        群相关操作
/////////////////////////////////////////////////////////////////////////////////
/**
 *  4.1 设置群组监听器
 */
- (void)setGroupListener:(id<V2TIMGroupListener>)listener;

/**
 *  4.2 创建群组
 *
 *  @param groupType 群类型，我们为您预定义好了四种常用的群类型，您也可以在控制台定义自己需要的群类型：
 *  - "Work"       ：工作群，成员上限 200  人，不支持由用户主动加入，需要他人邀请入群，适合用于类似微信中随意组建的工作群（对应老版本的 Private 群）。
 *  - "Public"     ：公开群，成员上限 2000 人，任何人都可以申请加群，但加群需群主或管理员审批，适合用于类似 QQ 中由群主管理的兴趣群。
 *  - "Meeting"    ：会议群，成员上限 6000 人，任何人都可以自由进出，且加群无需被审批，适合用于视频会议和在线培训等场景（对应老版本的 ChatRoom 群）。
 *  - "AVChatRoom" ：直播群，人数无上限，任何人都可以自由进出，消息吞吐量大，适合用作直播场景中的高并发弹幕聊天室。
 *
 *  @param groupID 自定义群组 ID，可以传 nil。传 nil 时系统会自动分配 groupID，并通过 succ 回调返回
 *  @param groupName 群名称，不能为 nil
 *
 *  @note 请注意如下特殊逻辑:
 *  - 不支持在同一个 SDKAPPID 下创建两个相同 groupID 的群
 */
- (void)createGroup:(NSString *)groupType groupID:(NSString*)groupID groupName:(NSString *)groupName succ:(V2TIMCreateGroupSucc)succ fail:(V2TIMFail)fail;

/**
 *  4.3 加入群组
 *
 *  @note 请注意如下特殊逻辑:
 *  - 工作群（Work）：不能主动入群，只能通过群成员调用 V2TIMManager+Group.h -> inviteUserToGroup 接口邀请入群。
 *  - 公开群（Public）：申请入群后，需要管理员审批，管理员在收到 V2TIMGroupListener -> onReceiveJoinApplication 回调后调用 V2TIMManager+Group.h -> getGroupApplicationList 接口处理加群请求。
 *  - 其他群：可以直接入群。
 */
- (void)joinGroup:(NSString*)groupID msg:(NSString*)msg succ:(V2TIMSucc)succ fail:(V2TIMFail)fail;

/**
 *  4.4 退出群组
 *
 *  @note 在公开群（Public）、会议（Meeting）和直播群（AVChatRoom）中，群主是不可以退群的，群主只能调用 dismissGroup 解散群组。
 */
- (void)quitGroup:(NSString*)groupID succ:(V2TIMSucc)succ fail:(V2TIMFail)fail;

/**
 *  4.5 解散群组
 *
 *  @note 请注意如下特殊逻辑:
 *  - Work：任何人都无法解散群组。
 *  - 其他群：群主可以解散群组。
 */
- (void)dismissGroup:(NSString*)groupID succ:(V2TIMSucc)succ fail:(V2TIMFail)fail;

//  4.6 更多功能，详见 V2TIMManager+Group.h

/////////////////////////////////////////////////////////////////////////////////
//                        资料相关操作
/////////////////////////////////////////////////////////////////////////////////

/**
 *  5.1 获取用户资料
 *  @note 请注意:
 *  - 获取自己的资料，传入自己的 ID 即可。
 *  - userIDList 建议一次最大 100 个，因为数量过多可能会导致数据包太大被后台拒绝，后台限制数据包最大为 1M。
 */
- (void)getUsersInfo:(NSArray<NSString *> *)userIDList succ:(V2TIMUserFullInfoListSucc)succ fail:(V2TIMFail)fail;

/**
 *  5.2 修改个人资料
 */
- (void)setSelfInfo:(V2TIMUserFullInfo *)Info succ:(V2TIMSucc)succ fail:(V2TIMFail)fail;

//  5.5 更多功能，详见 V2TIMManager+Friendship.h

/////////////////////////////////////////////////////////////////////////////////
//                        扩展接口
/////////////////////////////////////////////////////////////////////////////////

/**
 * 6.1 实验性 API 接口
 *
 * @param api 接口名称
 * @param param 接口参数
 *
 * @note 该接口提供一些实验性功能
 */
- (void)callExperimentalAPI:(NSString *)api
                      param:(NSObject *)param
                       succ:(V2TIMCallExperimentalAPISucc)succ
                       fail:(V2TIMFail)fail;

@end



NS_ASSUME_NONNULL_END
