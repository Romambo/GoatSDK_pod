//
//  TXIMSDKManager+Conversation.h
//  TXIMSDKManager
//
//  Created by Adminstration on 2021/6/15.
//

#import "TXIMSDKManager.h"
#import <ImSDK_Plus/V2TIMManager+Conversation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TXIMSDKManager (Conversation)
/**
 *  1.1 设置会话监听器
 */
- (void)setConversationListener:(id<V2TIMConversationListener>)listener;

/**
 *  1.2 获取会话列表
 *
 *  - 一个会话对应一个聊天窗口，比如跟一个好友的 1v1 聊天，或者一个聊天群，都是一个会话。
 *  - 由于历史的会话数量可能很多，所以该接口希望您采用分页查询的方式进行调用，每次分页拉取的个数建议为 100 个。
 *  - 该接口拉取的是本地缓存的会话，如果服务器会话有更新，SDK 内部会自动同步，然后在 V2TIMConversationListener 告知客户。
 *  - 该接口获取的会话默认已经按照会话 lastMessage -> timestamp 做了排序，timestamp 越大，会话越靠前。
 *  - 如果会话全部拉取完毕，成功回调里面的 isFinished 字段值为 YES。
 *
 *  @param nextSeq 分页拉取游标，第一次默认取传 0，后续分页拉传上一次分页拉取回调里的 nextSeq
 *  @param count  分页拉取的个数，一次分页拉取不宜太多，会影响拉取的速度，建议每次拉取 100 个会话
 */
- (void)getConversationList:(uint64_t)nextSeq count:(int)count succ:(V2TIMConversationResultSucc)succ fail:(V2TIMFail)fail;


/**
 * 1.3 获取单个会话
 *
 * @param conversationID  会话唯一 ID, C2C 单聊组成方式：[NSString stringWithFormat:@"c2c_%@",userID]；群聊组成方式为 [NSString stringWithFormat:@"group_%@",groupID]
 */
- (void)getConversation:(NSString *)conversationID succ:(V2TIMConversationSucc)succ fail:(V2TIMFail)fail;

/**
 * 1.4 获取指定会话列表
 *
 * @param conversationIDList 会话唯一 ID 列表，C2C 单聊组成方式：[NSString stringWithFormat:@"c2c_%@",userID]；群聊组成方式为 [NSString stringWithFormat:@"group_%@",groupID]
 */
- (void)getConversationList:(NSArray<NSString *> *)conversationIDList succ:(V2TIMConversationListSucc)succ fail:(V2TIMFail)fail;

/**
 *  1.5 删除会话以及该会话中的历史消息
 *
 * @param conversationID 会话唯一 ID，C2C 单聊组成方式：[NSString stringWithFormat:@"c2c_%@",userID]；群聊组成方式为 [NSString stringWithFormat:@"group_%@",groupID]
 *
 * @note 请注意:
 * - 该会话以及会话中的历史消息，会被 SDK 从本地和服务端一同删除掉，并且不可恢复。
 */
- (void)deleteConversation:(NSString *)conversationID succ:(V2TIMSucc)succ fail:(V2TIMFail)fail;

/**
 *  1.6 设置会话草稿
 *
 *  @param conversationID 会话唯一 ID，C2C 单聊组成方式：[NSString stringWithFormat:@"c2c_%@",userID]；群聊组成方式为 [NSString stringWithFormat:@"group_%@",groupID]
 *
 *  只在本地保存，不会存储 Server，不能多端同步，程序卸载重装会失效。
 */
- (void)setConversationDraft:(NSString *)conversationID draftText:(NSString *)draftText succ:(V2TIMSucc)succ fail:(V2TIMFail)fail;

/**
 *  1.7 设置会话置顶
 *
 * @param conversationID  会话唯一 ID，C2C 单聊组成方式：[NSString stringWithFormat:@"c2c_%@",userID]；群聊组成方式为 [NSString stringWithFormat:@"group_%@",groupID]
 * @param isPinned 是否置顶
 */
- (void)pinConversation:(NSString *)conversationID isPinned:(BOOL)isPinned succ:(V2TIMSucc)succ fail:(V2TIMFail)fail;

/**
 *  1.8 获取所有会话的未读消息总数
 */
- (void)getTotalUnreadMessageCount:(V2TIMTotalUnreadMessageCountSucc)succ fail:(V2TIMFail)fail;

@end

NS_ASSUME_NONNULL_END
