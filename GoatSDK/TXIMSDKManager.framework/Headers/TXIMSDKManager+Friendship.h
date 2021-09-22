//
//  TXIMSDKManager+Friendship.h
//  TXIMSDKManager
//
//  Created by Adminstration on 2021/6/15.
//

#import "TXIMSDKManager.h"
#import <ImSDK_Plus/V2TIMManager+Friendship.h>

NS_ASSUME_NONNULL_BEGIN

@interface TXIMSDKManager (Friendship)
/////////////////////////////////////////////////////////////////////////////////
//
//                         关系链和用户资料监听器
//
/////////////////////////////////////////////////////////////////////////////////

/**
 *  1.1 设置关系链监听器
 */
- (void)setFriendListener:(id<V2TIMFriendshipListener>)listener;

/////////////////////////////////////////////////////////////////////////////////
//
//                       好友添加、删除、列表获取、资料设置相关接口
//
/////////////////////////////////////////////////////////////////////////////////

/**
 *  2.1 获取好友列表
 */
- (void)getFriendList:(V2TIMFriendInfoListSucc)succ fail:(V2TIMFail)fail;

/**
 *  2.2 获取指定好友资料
 *  @param userIDList 好友 userID 列表
 *                   - ID 建议一次最大 100 个，因为数量过多可能会导致数据包太大被后台拒绝，后台限制数据包最大为 1M。
 */
- (void)getFriendsInfo:(NSArray<NSString *> *)userIDList succ:(V2TIMFriendInfoResultListSucc)succ fail:(V2TIMFail)fail;

/**
 *  2.3 设置指定好友资料
 */
- (void)setFriendInfo:(V2TIMFriendInfo *)info succ:(V2TIMSucc)succ fail:(V2TIMFail)fail;

/**
 *  2.4 搜索好友列表
 *
 *  SDK 会根据条件搜索好友备注、好友昵称以及好友 userID 包含于关键字列表 keywordList 的所有好友并返回好友信息列表。关键字列表最多支持5个。
 */
- (void)searchFriends:(V2TIMFriendSearchParam *)searchParam succ:(V2TIMFriendInfoListSucc)succ fail:(V2TIMFail)fail;

/**
 *  2.5 添加好友
 */
- (void)addFriend:(V2TIMFriendAddApplication *)application succ:(V2TIMFriendOperationResultSucc)succ fail:(V2TIMFail)fail;

/**
 *  2.6 删除好友
 *  @param userIDList 要删除的好友 userID 列表
 *                   - ID 建议一次最大 100 个，因为数量过多可能会导致数据包太大被后台拒绝，后台限制数据包最大为 1M。
 *  @param deleteType 删除类型（单向好友、双向好友）
 */
- (void)deleteFromFriendList:(NSArray *)userIDList deleteType:(V2TIMFriendType)deleteType succ:(V2TIMFriendOperationResultListSucc)succ fail:(V2TIMFail)fail;

/**
 *  2.7 检查指定用户的好友关系
 *  @param userIDList 要检查的 userID 列表
 *  @param checkType 检查类型 （单向好友检查、双向好友检查）
 *  @param succ 成功后的回调
 *  @param fail 失败后的回调
 *
 *  @note checkType 的使用需要注意：
 *  - checkType 如果传入 V2TIM_FRIEND_TYPE_SINGLE，结果返回：V2TIM_FRIEND_RELATION_TYPE_NONE、V2TIM_FRIEND_RELATION_TYPE_IN_MY_FRIEND_LIST 两种情况
 *  - checkType 如果传入 V2TIM_FRIEND_TYPE_BOTH，结果返回：V2TIM_FRIEND_RELATION_TYPE_NONE、V2TIM_FRIEND_RELATION_TYPE_IN_MY_FRIEND_LIST、
 *                                                 V2TIM_FRIEND_RELATION_TYPE_IN_OTHER_FRIEND_LIST、V2TIM_FRIEND_RELATION_TYPE_BOTH_WAY 四种情况
 */
- (void)checkFriend:(NSArray<NSString *> *)userIDList checkType:(V2TIMFriendType)checkType succ:(V2TIMFriendCheckResultListSucc)succ fail:(V2TIMFail)fail;

/////////////////////////////////////////////////////////////////////////////////
//
//                          好友申请、删除相关逻辑
//
/////////////////////////////////////////////////////////////////////////////////

/**
 *  3.1 获取好友申请列表
 */
- (void)getFriendApplicationList:(V2TIMFriendApplicationResultSucc)succ fail:(V2TIMFail)fail;

/**
 *  3.2 同意好友申请
 *
 *  @param application 好友申请信息，getFriendApplicationList 成功后会返回
 *  @param acceptType 建立单向/双向好友关系
 */
- (void)acceptFriendApplication:(V2TIMFriendApplication *)application type:(V2TIMFriendAcceptType)acceptType succ:(V2TIMFriendOperationResultSucc)succ fail:(V2TIMFail)fail;

/**
 *  3.3 拒绝好友申请
 *
 *  @param application 好友申请信息，getFriendApplicationList 成功后会返回
 */
- (void)refuseFriendApplication:(V2TIMFriendApplication *)application succ:(V2TIMFriendOperationResultSucc)succ fail:(V2TIMFail)fail;

/**
 *  3.4 删除好友申请
 *
 *  @param application 好友申请信息，getFriendApplicationList 成功后会返回
 */
- (void)deleteFriendApplication:(V2TIMFriendApplication *)application succ:(V2TIMSucc)succ fail:(V2TIMFail)fail;

/**
 *  3.5 设置好友申请已读
 */
- (void)setFriendApplicationRead:(V2TIMSucc)succ fail:(V2TIMFail)fail;


/////////////////////////////////////////////////////////////////////////////////
//
//                          黑名单
//
/////////////////////////////////////////////////////////////////////////////////

/**
 *  4.1 添加用户到黑名单
 */
- (void)addToBlackList:(NSArray *)userIDList succ:(V2TIMFriendOperationResultListSucc)succ fail:(V2TIMFail)fail;

/**
 *  4.2 把用户从黑名单中删除
 */
- (void)deleteFromBlackList:(NSArray *)userIDList succ:(V2TIMFriendOperationResultListSucc)succ fail:(V2TIMFail)fail;

/**
 *  4.3 获取黑名单列表
 */
- (void)getBlackList:(V2TIMFriendInfoListSucc)succ fail:(V2TIMFail)fail;


/////////////////////////////////////////////////////////////////////////////////
//
//                          好友分组
//
/////////////////////////////////////////////////////////////////////////////////

/**
 *  5.1 新建好友分组
 *
 *  @param groupName  分组名称
 *  @param userIDList 要添加到分组中的好友
 */
- (void)createFriendGroup:(NSString *)groupName userIDList:(NSArray *)userIDList succ:(V2TIMFriendOperationResultListSucc)succ fail:(V2TIMFail)fail;

/**
 *  5.2 获取分组信息
 *
 *  @param groupNameList  要获取信息的好友分组名称列表,传入 nil 获得所有分组信息
 */
- (void)getFriendGroupList:(NSArray *)groupNameList succ:(V2TIMFriendGroupListSucc)succ fail:(V2TIMFail)fail;

/**
 *  5.3 删除好友分组
 */
- (void)deleteFriendGroup:(NSArray *)groupNameList succ:(V2TIMSucc)succ fail:(V2TIMFail)fail;

/**
 *  5.4 修改好友分组的名称
 */
- (void)renameFriendGroup:(NSString*)oldName newName:(NSString*)newName succ:(V2TIMSucc)succ fail:(V2TIMFail)fail;

/**
 *  5.5 添加好友到一个好友分组
 */
- (void)addFriendsToFriendGroup:(NSString *)groupName userIDList:(NSArray *)userIDList succ:(V2TIMFriendOperationResultListSucc)succ fail:(V2TIMFail)fail;

/**
 *  5.6 从好友分组中删除好友
 */
- (void)deleteFriendsFromFriendGroup:(NSString *)groupName userIDList:(NSArray *)userIDList succ:(V2TIMFriendOperationResultListSucc)succ fail:(V2TIMFail)fail;

@end

NS_ASSUME_NONNULL_END
