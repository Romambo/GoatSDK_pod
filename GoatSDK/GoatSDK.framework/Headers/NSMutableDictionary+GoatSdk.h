//
//  NSMutableDictionary-GTSDK.h
//  GTSDK
//
//  Created by choici on 2019/3/14.
//  Copyright © 2019 goatgames. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

extern NSString * __nonnull const mSku;
extern NSString * __nonnull const mType;
extern NSString * __nonnull const mPrice;
extern NSString * __nonnull const mPriceAmountMicros;
extern NSString * __nonnull const mPriceCurrencyCode;
extern NSString * __nonnull const mPriceCurrencySymbol;
extern NSString * __nonnull const mTitle;
extern NSString * __nonnull const mDescription;
extern NSString * __nonnull const mJson;
extern NSString * __nonnull const mFormatPrice;


typedef void(^GTCompletionHandler)(int code, id _Nullable response);


//服务器接口类型
typedef NS_ENUM(NSUInteger, GoatEnvironmentType) {
    GoatEnvironmentTypeDevelop = 1,//开发环境
    GoatEnvironmentTypePreparation,//预发布环境
    GoatEnvironmentTypeProduction,//正式环境
};

typedef NS_ENUM(NSUInteger, GoatReviewType) {
    GoatReviewTypeOnlyReview,
    GoatReviewTypeReviewAndText,
    GoatReviewTypeTurnToStore,
};


typedef NS_ENUM(NSUInteger, GoatIDFARequireStatus) {
    GoatIDFARequireStatusSdkDecline,
    GoatIDFARequireStatusSystemDecline,
    GoatIDFARequireStatusSystemAllow,
};


typedef NS_ENUM(NSUInteger, GoatShowATTChannel) {
    GoatShowATTChannelSDK,
    GoatShowATTChannelCP,
};

typedef NS_ENUM(NSInteger, AppTrackingAuthorizationStatus) {
    AppTrackingAuthorizationStatusNotDetermined = 0,       //0：用户尚未收到请求
    AppTrackingAuthorizationStatusRestricted = 1,          //1：用户设备受限
    AppTrackingAuthorizationStatusDenied = 2,              //2：用户拒绝提供 IDFA
    AppTrackingAuthorizationStatusAuthorized = 3,          //3：用户授权访问 IDFA
    AppTrackingAuthorizationStatusNotAvailable = -1,       //-1：状态不可用
    AppTrackingAuthorizationStatusSDKDenied = -2,          //-2：SDK服务器拒绝
    AppTrackingAuthorizationStatusPagesAllow = 8,          //8：用户引导页面允许弹出IDFA
    AppTrackingAuthorizationStatusPagesLater = 9,          //9：用户引导页面拒绝弹出IDFA
    AppTrackingAuthorizationStatusPagesNotAvailable = -3,  //-3：用户引导页面不可用
};



/**
 第三方登录平台类型。用于使用第三方社交账号登录。

 - GTLoginTypeDefault: 直接登录游戏（默认）
 - GTLoginTypeFacebook: 通过Facebook登录/绑定到游戏
 - GTLoginTypeGameCenter: 通过GameCenter登录/绑定到游戏
 - GTLoginTypeCommon: 通过邮箱账户登录/绑定游戏
 - GTLoginTypeApple:通过苹果账户登录/绑定游戏
 */

typedef NS_ENUM(NSUInteger, GTLoginType) {
    GTLoginTypeDefault,
    GTLoginTypeFacebook,
    GTLoginTypeGameCenter,
    GTLoginTypeCommon,
    GTLoginTypeApple,
};

/**
 第三方统计平台类型。用户事件点位上报。
 
 - GTThirdAdvertisementNone: 不上报
 - GTThirdAdvertisementFacebook: 上报到Facebook平台
 - GTThirdAdvertisementFirebase: 上报到Firebase平台
 - GTThirdAdvertisementAdjust: 上报到Adjust平台
 - GTThirdAdvertisementAllChannel: 不区分渠道，即采用所有SDK所接入的渠道均上报
 */
typedef NS_OPTIONS(NSUInteger, GTThirdAdvertisementChannel) {
    GTThirdAdvertisementNone = 0,
    GTThirdAdvertisementFacebook = 1<<0,
    GTThirdAdvertisementFirebase = 1<<1,
    GTThirdAdvertisementAdjust = 1<<2,
    GTThirdAdvertisementAllChannel = (GTThirdAdvertisementFacebook | GTThirdAdvertisementFirebase | GTThirdAdvertisementAdjust),
};


#define GT_SERVER_SUCCESS 0 //服务器返回成功
#define GT_SERVER_FAILURE -1//服务器返回失败
#define GT_SERVER_CONNECT_FAILED -1000//服务器无法访问


NS_ASSUME_NONNULL_BEGIN

@interface NSMutableDictionary (GoatSdk)

#pragma mark - 用户中心
- (void)gt_setupUserCenterParamsServerName:(NSString *)serverName
                                  serverID:(NSString *)serverID
                                  roleName:(NSString *)roleName
                                    roleID:(NSString *)roleID
                                 roleLevel:(NSString *)roleLevel;



#pragma mark - 账号功能

/**
 用户登录。
 
 @param loginType 社交登录方式。根据枚举GTLoginType传入相对应的参数
 @param viewController 当前页面的控制器
 @param account 账户(邮箱） 非邮箱登录不传
 @param password 账户密码   非邮箱登录不传
 @param completionHandler 完成之后的回调
 */

- (void)gt_setupLoginParamsLoginType:(GTLoginType)loginType
                      viewController:(UIViewController *)viewController
                             account:(NSString *_Nullable)account
                            password:(NSString *_Nullable)password
                   completionHandler:(GTCompletionHandler)completionHandler;



/**
 用户绑定。使用游戏账号绑定当前游客登录或社交登录方式的游戏进程
 
 @param bindType 绑定的社交方式
 @param viewController 当前的视图控制器
 @param account 账户名（邮箱）非邮箱绑定不传
 @param password 账户密码    非邮箱绑定不传
 @param verificationCode 验证码 非邮箱绑定不传
 @param completionHandler 完成之后的回调
 */
- (void)gt_setupAccountBindParamsType:(GTLoginType)bindType
                       viewController:(UIViewController *)viewController
                              account:(NSString *_Nullable)account
                             password:(NSString *_Nullable)password
                     verificationCode:(NSString *_Nullable)verificationCode
                    completionHandler:(GTCompletionHandler)completionHandler;

/**
 退出登录。退出当前所登录的游戏账号
 
 @param completionHandler 完成之后的回调
 */
- (void)gt_setupAccountLogOutParamsHandler:(GTCompletionHandler)completionHandler;

/**
 修改密码
 
 @param oldPsw 旧密码
 @param newPsw 新密码
 @param completionHandler 完成之后的回调
 */
- (void)gt_setupAccountPasswordAlterParamsOldPaw:(NSString *)oldPsw
                                          newPsw:(NSString *)newPsw
                               completionHandler:(GTCompletionHandler)completionHandler;

/**
 找回密码
 
 @param account 账号（邮箱）
 @param password 账户密码
 @param verificationCode 验证码
 @param completionHandler 完成之后的回调
 */
- (void)gt_setupAccountResetPasswordParamsAccount:(NSString *)account
                                         password:(NSString *)password
                                 verificationCode:(NSString *)verificationCode
                                completionHandler:(GTCompletionHandler)completionHandler;

/**
 发送验证码 向注册邮箱发送安全验证码
 
 @param account 登录账号（邮箱）
 @param completionHandler 完成之后的回调
 */
- (void)gt_setupAccountSendVerificationCodeParamsAccount:(NSString *)account
                                       completionHandler:(GTCompletionHandler)completionHandler;


/**
 发送验证码 向注册邮箱发送安全验证码
 
 @param account 登录账号（邮箱）
 @param completionHandler 完成之后的回调
 */
- (void)gt_setupAccountRegisterParamsAccount:(NSString *)account
                                    password:(NSString *)password
                           completionHandler:(GTCompletionHandler)completionHandler;


/**
获取未读消息

@param completionHandler 完成之后的回调
*/
- (void)gt_setupAccountUnreadMeaasgeCompletionHandler:(GTCompletionHandler)completionHandler;



#pragma mark - 分享功能

/**
 Facebook分享。分享图片和链接
 
 @param content 分享的图片或链接
   @disussion 照片大小必须小于 12MB
   @disussion 用户需要安装版本 7.0 或以上的原生 iOS 版 Facebook 应用
 @param viewController 当前的视图控制器
 @param completionHandler 完成之后的回调
 */
- (void)gt_setupShareParamsContent:(id)content
                     viewController:(UIViewController *)viewController
                  completionHandler:(GTCompletionHandler)completionHandler;



#pragma mark - 推送功能

/**
 APNS远程推送。用于接收远程通知
 
 @param 已在内部集成
 @param 在应用启动完成后设置代理
 @param 在Appdelegate中是实现代理方法gt_didReceiveRemoteNotification:userInfo即可接收消息的响应
 */


#pragma mark - 支付功能
/**
 苹果内支付。调用苹果支付完成储值功能
 
 @param product 付费点id
 @param description 商品描述
 @param amount 商品金额
 @param currency 币种
 @param serverName 服务器名称
 @param serverID 服务器id
 @param roleName 角色名称
 @param roleID 角色id
 @param roleLevel 角色等级
 @param controller 当前控制器
 @param cpOrderId cp订单号
 @param ext       透传参数
 @param completionHandler 完成之后的回调
 */
- (void)gt_setupPayParamsProduct:(NSString *)product
                     description:(NSString *)description
                          amount:(NSString *)amount
                        currency:(NSString *)currency
                      serverName:(NSString *)serverName
                        serverID:(NSString *)serverID
                        roleName:(NSString *)roleName
                          roleID:(NSString *)roleID
                       roleLevel:(NSString *)roleLevel
                       cpOrderId:(NSString *)cpOrderId
                  viewController:(UIViewController *)controller
                             ext:(NSString *)ext
               completionHandler:(GTCompletionHandler)completionHandler;

/**
 查询支付结果。
 
 @param cpOrderId cp订单号
 @param ext       透传参数
 @param completionHandler 完成之后的回调
 */
- (void)gt_setupQueryOrderCpOrderId:(NSString *)cpOrderId
                           ext:(NSString *)ext
             completionHandler:(GTCompletionHandler)completionHandler;



#pragma mark - 客服功能
/**
 客服。展示客服页面
 
 @param controller 当前视图的控制器
 @param serverName 服务器名称
 @param serverID 服务器id
 @param roleName 角色名称
 @param roleID 角色id
 @param roleLevel 角色等级
 */
- (void)gt_setupCustomerParamsViewController:(UIViewController *)controller
                                  serverName:(NSString *)serverName
                                    serverID:(NSString *)serverID
                                    roleName:(NSString *)roleName
                                      roleID:(NSString *)roleID
                                   roleLevel:(NSString *)roleLevel;


#pragma mark - 用户协议
/**
 玩家守则。展示用户协议
 
 @param controller 当前视图的控制器
 @param serverName 服务器名称
 @param serverID 服务器id
 @param roleName 角色名称
 @param roleID 角色id
 @param roleLevel 角色等级
 */
- (void)gt_setupAgreementParamsViewController:(UIViewController *)controller
                                  serverName:(NSString *)serverName
                                    serverID:(NSString *)serverID
                                    roleName:(NSString *)roleName
                                      roleID:(NSString *)roleID
                                   roleLevel:(NSString *)roleLevel;



#pragma mark - 归因功能
/**
 配置普通事件上报接口gt_TrackEvent的参数。
 
 @param eventName 上报的事件定义名称
 @param serverName 服务器名称
 @param serverID 服务器id
 @param roleName 角色名称
 @param roleID 角色id
 @param roleLevel 角色等级
 @param remark 扩展参数（可选，键值按事件所需扩展内容的而定）
 */
- (void)gt_setupEventTrackParamsEventName:(nonnull NSString *)eventName
                               serverName:(NSString *)serverName
                                 serverID:(NSString *)serverID
                                 roleName:(NSString *)roleName
                                   roleID:(NSString *)roleID
                                roleLevel:(nonnull NSString *)roleLevel
                                   remark:(nullable NSDictionary *)remark;


/**
 配置普通事件上报接口gt_TrackEvent的参数。
 
 @param eventName 上报的事件定义名称
 @param serverName 服务器名称
 @param serverID 服务器id
 @param roleName 角色名称
 @param roleID 角色id
 @param roleLevel 角色等级
 @param remark 扩展参数（可选，键值按事件所需扩展内容的而定）
 @param channel 上报渠道
 */
- (void)gt_setupEventTrackParamsEventName:(nonnull NSString *)eventName
                               serverName:(NSString *)serverName
                                 serverID:(NSString *)serverID
                                 roleName:(NSString *)roleName
                                   roleID:(NSString *)roleID
                                roleLevel:(nonnull NSString *)roleLevel
                                   remark:(nullable NSDictionary *)remark
                                  channel:(GTThirdAdvertisementChannel)channel;



/**
 配置绑定角色上报接口gt_bindRole的参数。
 
 @param serverName 服务器名称
 @param serverID 服务器id
 @param roleName 角色名称
 @param roleID 角色id
 @param roleLevel 角色等级
 */
- (void)gt_setupBindParamsRoleID:(nonnull NSString *)roleID
                               serverName:(NSString *)serverName
                                 serverID:(NSString *)serverID
                                 roleName:(NSString *)roleName
                                roleLevel:(nonnull NSString *)roleLevel;






/**
 配置游戏内容上报接口gt_uploadGamwInfo的参数。
 
 @param info 游戏内容参数
 @param completionHandler 完成之后的回调
 */
- (void)gt_setupUploadGameInfo:(NSString *)info
                      completionHandler:(GTCompletionHandler)completionHandler;



#pragma mark - 评分功能


/**
 应用内评分功能（弹出5星）。

 @param appID app在App Store的应用id
 @param controller 当前控制器
 */
- (void)gt_setupEvaluationParamsAppID:(nonnull NSString *)appID
                       viewController:(UIViewController *)controller;

- (void)gt_setupEvaluationParamsAppID:(nonnull NSString *)appId
viewController:(UIViewController *)controller type:(GoatReviewType)type;


#pragma mark - 广告功能

- (void)gt_setupRequiredAdParamsAdName:(NSString *)adName
                     completionHandler:(void(^ _Nullable)(NSError *error))completionHandler;

- (void)gt_setupAdParamsController: (UIViewController *)controller
                                   serverName:(NSString *)serverName
                                     serverID:(NSString *)serverID
                                     roleName:(NSString *)roleName
                                       roleID:(NSString *)roleID
                                    roleLevel:(NSString *)roleLevel
                                          ext:(NSString *)ext
                            completionHandler:(void (^ _Nullable)(NSUInteger))completionHandler;

@end

NS_ASSUME_NONNULL_END
