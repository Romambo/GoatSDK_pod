//
//  TXIMSDKManager+Group.h
//  TXIMSDKManager
//
//  Created by Adminstration on 2021/6/15.
//

#import "TXIMSDKManager.h"
#import <ImSDK_Plus/V2TIMManager+Group.h>


NS_ASSUME_NONNULL_BEGIN

@interface TXIMSDKManager (Group)
/////////////////////////////////////////////////////////////////////////////////
//                         群管理
/////////////////////////////////////////////////////////////////////////////////

/**
 *  1.1 创建自定义群组（高级版本：可以指定初始的群成员）
 *
 *  @param info 自定义群组信息，可以设置 groupID | groupType | groupName | notification | introduction | faceURL 字段
 *  @param memberList 指定初始的群成员（直播群 AVChatRoom 不支持指定初始群成员，memberList 请传 nil）
 *
 *  @note 其他限制请参考 V2TIMManager.h -> createGroup 注释
 */
- (void)createGroup:(V2TIMGroupInfo*)info memberList:(NSArray<V2TIMCreateGroupMemberInfo *>*) memberList succ:(V2TIMCreateGroupSucc)succ fail:(V2TIMFail)fail;

/**
 *  1.2 获取当前用户已经加入的群列表
 *
 *  @note
 *  - 直播群（AVChatRoom）不支持该 API
 *  - 该接口有频限检测，SDK 限制调用频率为 1 秒 10 次，超过限制后会报 ERR_SDK_COMM_API_CALL_FREQUENCY_LIMIT （7008）错误
 */
- (void)getJoinedGroupList:(V2TIMGroupInfoListSucc)succ fail:(V2TIMFail)fail;

/////////////////////////////////////////////////////////////////////////////////
//                         群资料管理
/////////////////////////////////////////////////////////////////////////////////

/**
 *  2.1 拉取群资料
 *
 *  @param groupIDList 群组 ID 列表
 */
- (void)getGroupsInfo:(NSArray<NSString *> *)groupIDList succ:(V2TIMGroupInfoResultListSucc)succ fail:(V2TIMFail)fail;

/**
 *  2.2 搜索群列表
 *
 *  SDK 会搜索群名称包含于关键字列表 keywordList 的所有群并返回群信息列表。关键字列表最多支持5个。
 */
- (void)searchGroups:(V2TIMGroupSearchParam *)searchParam succ:(V2TIMGroupInfoListSucc)succ fail:(V2TIMFail)fail;

/**
 *  2.3 修改群资料
 */
- (void)setGroupInfo:(V2TIMGroupInfo *)info succ:(V2TIMSucc)succ fail:(V2TIMFail)fail;

/**
 *  2.4 初始化群属性，会清空原有的群属性列表
 *
 * @note
 * attributes 的使用限制如下：
 *  - 目前只支持 AVChatRoom
 *  - key 最多支持16个，长度限制为32字节
 *  - value 长度限制为4k
 *  - 总的 attributes（包括 key 和 value）限制为16k
 *  - initGroupAttributes、setGroupAttributes、deleteGroupAttributes 接口合并计算， SDK 限制为5秒10次，超过后回调8511错误码；后台限制1秒5次，超过后返回10049错误码
 *  - getGroupAttributes 接口 SDK 限制5秒20次
 */
- (void)initGroupAttributes:(NSString*)groupID attributes:(NSDictionary<NSString *,NSString *> *)attributes succ:(V2TIMSucc)succ fail:(V2TIMFail)fail;

/**
 *  2.5 设置群属性，已有该群属性则更新其 value 值，没有该群属性则添加该群属性。
 */
- (void)setGroupAttributes:(NSString*)groupID attributes:(NSDictionary<NSString *,NSString *> *)attributes succ:(V2TIMSucc)succ fail:(V2TIMFail)fail;

/**
 *  2.6 删除群指定属性，keys 传 nil 则清空所有群属性。
 */
- (void)deleteGroupAttributes:(NSString*)groupID keys:(NSArray<NSString *> *)keys succ:(V2TIMSucc)succ fail:(V2TIMFail)fail;

/**
 *  2.7 获取群指定属性，keys 传 nil 则获取所有群属性。
 */
- (void)getGroupAttributes:(NSString*)groupID keys:(NSArray<NSString *> *)keys succ:(V2TIMGroupAttributeListSucc)succ fail:(V2TIMFail)fail;

/**
 * 2.8 获取指定群在线人数
 *
 * @param groupID 群id
 * @param succ 成功回调
 * @param fail 失败回调
 *
 * @note 请注意
 * - 目前只支持：直播群（ AVChatRoom）。
 * - 该接口有频限检测，SDK 限制调用频率为60秒1次。
 */
- (void)getGroupOnlineMemberCount:(NSString*)groupID succ:(V2TIMGroupOnlineMemberCountSucc)succ fail:(V2TIMFail)fail;


/////////////////////////////////////////////////////////////////////////////////
//                         群成员管理
/////////////////////////////////////////////////////////////////////////////////
/**
 *  3.1 获取群成员列表
 *
 *  @param filter   指定群成员类型
 *  @param nextSeq  分页拉取标志，第一次拉取填0，回调成功如果 nextSeq 不为零，需要分页，传入再次拉取，直至为 0。
 *
 *  @note 直播群（AVChatRoom）的特殊限制：
 *  - 不支持管理员角色的拉取，群成员个数最大只支持 31 个（新进来的成员会排前面），用户每次登录后，都需要重新加入群组，否则拉取群成员会报 10007 错误码。
 *  - 群成员资料信息仅支持 userID | nickName | faceURL | role 字段。
 *  - role 字段不支持管理员角色，如果您的业务逻辑依赖于管理员角色，可以使用群自定义字段 groupAttributes 管理该角色。
 */
- (void)getGroupMemberList:(NSString*)groupID filter:(V2TIMGroupMemberFilter)filter nextSeq:(uint64_t)nextSeq succ:(V2TIMGroupMemberInfoResultSucc)succ fail:(V2TIMFail)fail;

/**
 *  3.2 指定的群成员资料
 */
- (void)getGroupMembersInfo:(NSString*)groupID memberList:(NSArray<NSString*>*)memberList succ:(V2TIMGroupMemberInfoListSucc)succ fail:(V2TIMFail)fail;

/**
 *  3.3 搜索指定的群成员资料
 *
 *  SDK 会在本地搜索指定群 ID 列表中，群成员信息（名片、好友备注、昵称、userID）包含于关键字列表 keywordList 的所有群成员并返回群 ID 和群成员列表的 map，关键字列表最多支持5个。
 *
 * @param searchParam 搜索参数
 */
- (void)searchGroupMembers:(V2TIMGroupMemberSearchParam *)searchParam
                      succ:(V2TIMGroupMemberInfoListSearchSucc)succ
                      fail:(V2TIMFail)fail;
/**
 *  3.4 修改指定的群成员资料
 */
- (void)setGroupMemberInfo:(NSString*)groupID info:(V2TIMGroupMemberFullInfo *)info succ:(V2TIMSucc)succ fail:(V2TIMFail)fail;

/**
 *  3.5 禁言（只有管理员或群主能够调用）
 */
- (void)muteGroupMember:(NSString*)groupID member:(NSString*)userID muteTime:(uint32_t)seconds succ:(V2TIMSucc)succ fail:(V2TIMFail)fail;

/**
 *  3.6 邀请他人入群
 *
 *  @note 请注意不同类型的群有如下限制：
 *  - 工作群（Work）：群里的任何人都可以邀请其他人进群。
 *  - 会议群（Meeting）和公开群（Public）：只有通过rest api 使用 App 管理员身份才可以邀请其他人进群。
 *  - 直播群（AVChatRoom）：不支持此功能。
 */
- (void)inviteUserToGroup:(NSString*)groupID userList:(NSArray<NSString *>*)userList succ:(V2TIMGroupMemberOperationResultListSucc)succ fail:(V2TIMFail)fail;

/**
 *  3.7 踢人
 *
 *  @note 请注意不同类型的群有如下限制：
 * - 工作群（Work）：只有群主或 APP 管理员可以踢人。
 * - 公开群（Public）、会议群（Meeting）：群主、管理员和 APP 管理员可以踢人
 * - 直播群（AVChatRoom）：只支持禁言（muteGroupMember），不支持踢人。
 */
- (void)kickGroupMember:(NSString*)groupID memberList:(NSArray<NSString *>*)memberList reason:(NSString*)reason succ:(V2TIMGroupMemberOperationResultListSucc)succ fail:(V2TIMFail)fail;

/**
 *  3.8 切换群成员的角色
 *
 *  @note 请注意不同类型的群有如下限制：
 *  - 公开群（Public）和会议群（Meeting）：只有群主才能对群成员进行普通成员和管理员之间的角色切换。
 *  - 其他群不支持设置群成员角色。
 *  - 转让群组请调用 @ref transferGroupOwner 接口。
 *  - 会议群（Meeting）切换群成员角色之后，不会有 onGrantAdministrator 和 onRevokeAdministrator 通知回调
 *  - 切换的角色支持普通群成员（ V2TIM_GROUP_MEMBER_ROLE_MEMBER） 和管理员（V2TIM_GROUP_MEMBER_ROLE_ADMIN
 */
- (void)setGroupMemberRole:(NSString*)groupID member:(NSString *)userID newRole:(V2TIMGroupMemberRole)role succ:(V2TIMSucc)succ fail:(V2TIMFail)fail;

/**
 *  3.9 转让群主
 *
 *  @note 请注意不同类型的群有如下限制：
 *  - 普通类型的群（Work、Public、Meeting）：只有群主才有权限进行群转让操作。
 *  - 直播群（AVChatRoom）：不支持转让群主。
 */
- (void)transferGroupOwner:(NSString*)groupID member:(NSString*)userID succ:(V2TIMSucc)succ fail:(V2TIMFail)fail;


/////////////////////////////////////////////////////////////////////////////////
//                         加群申请
/////////////////////////////////////////////////////////////////////////////////

/**
 *  4.1 获取加群的申请列表
 */
- (void)getGroupApplicationList:(V2TIMGroupApplicationResultSucc)succ fail:(V2TIMFail)fail;

/**
 *  4.2 同意某一条加群申请
 */
- (void)acceptGroupApplication:(V2TIMGroupApplication *)application reason:(NSString*)reason succ:(V2TIMSucc)succ fail:(V2TIMFail)fail;

/**
 *  4.3 拒绝某一条加群申请
 */
- (void)refuseGroupApplication:(V2TIMGroupApplication *)application reason:(NSString*)reason succ:(V2TIMSucc)succ fail:(V2TIMFail)fail;

/**
 *  4.4 标记申请列表为已读
 */
- (void)setGroupApplicationRead:(V2TIMSucc)succ fail:(V2TIMFail)fail;


@end

NS_ASSUME_NONNULL_END
