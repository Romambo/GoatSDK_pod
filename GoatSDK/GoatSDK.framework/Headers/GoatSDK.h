//
//  GT.h
//  GTSDK
//
//  Created by choici on 2019/3/7.
//  Copyright © 2019 goatgames. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NSMutableDictionary+GoatSdk.h"


NS_ASSUME_NONNULL_BEGIN


@protocol GTNotificationDelegate <NSObject>

@optional

- (void)gt_didReceiveRemoteNotification:(NSDictionary *)userInfo;

@end


@protocol GT3DTouchPerformActionDelegate <NSObject>

@optional

- (void)gt_didReceive3DTouchPerformActionType:(NSString *)actionType;

@end



@interface GoatSDK : NSObject

 /**
 
  @dicussion   SDK版本最低支持iOS 9
 */

+ (instancetype)sharedInstance;

@property (nullable,nonatomic, weak) id<GTNotificationDelegate> delegate;
@property (nullable,nonatomic, weak) id<GT3DTouchPerformActionDelegate>touchDelegate;


#pragma mark - 测试用例

+ (void)gt_resetDeviceId;

+ (void)gt_setAdjLogLevel:(NSUInteger)logLevel;

+ (void)addTestingDevices:(NSArray *)testingDevices;


#pragma mark - 项目功能

/**
 @abstract      环境配置功能
 @disussion     配置开发环境NO,生产环境YES
 */
+ (void)gt_production:(BOOL)isproduction application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

+ (void)gt_initEnvironment:(GoatEnvironmentType)environmentType application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;


#pragma mark - 账号功能

+ (void)gt_setupUserCenterScreenDirection:(NSString *)screenDirection;

+ (void)gt_openUserCenterOnController:(UIViewController *)controller gamesInfo:(NSMutableDictionary *)gamesInfo loginCompletionHandler:(GTCompletionHandler)loginHandler logoutCompletionHandler:(GTCompletionHandler)logoutHandler;


+ (void)gt_loginUserCenterWithViewController:(UIViewController *)controller loginCompletionHandler:(GTCompletionHandler)loginHandler;


/**
 @abstract      登录功能
 @param loginParams 登录所需参数，请使用"NSMutableDictionary+GTSDK"中的gt_setupLoginParams配置
 */
+ (id)gt_login:(nonnull NSMutableDictionary *)loginParams;


/**
 @abstract      绑定功能
 @param bindParams 绑定所需参数，请使用"NSMutableDictionary+GTSDK"中的gt_setupAccountBindParams配置
 */
+ (id)gt_bind:(nonnull NSMutableDictionary *)bindParams;

/**
 @abstract      退出登录功能
 */
+ (void)gt_logout;

/**
 @abstract      修改密码功能
 @param alterPasswordParams 修改密码参数，请使用"NSMutableDictionary+GTSDK"中的gt_setupAccountPasswordAlertParams配置
 */
+ (void)gt_alterPassword:(nonnull NSMutableDictionary *)alterPasswordParams;

/**
 @abstract      找回密码功能
 @param resetPasswordParams 找回密码所需参数，请使用"NSMutableDictionary+GTSDK"中的gt_setupAccountResetPasswordParams配置
 */
+ (void)gt_resetPassword:(nonnull NSMutableDictionary *)resetPasswordParams;

/**
 @abstract      发送邮箱验证码功能
 @param sendVerityCodeParams 验证码发送相关信息，请使用"NSMutableDictionary+GTSDK"中的gt_setupAccountSendVerificationCodeParams配置
 */
+ (void)gt_sendVerificationCode:(nonnull NSMutableDictionary *)sendVerityCodeParams;



/**
 @abstract      获取未读信息
 */
+ (void)gt_getCustomerUnreadMessage:(nonnull NSMutableDictionary *)unreadParams;


#pragma mark - 分享功能

/**
 @abstract      分享图片或链接
 @param shareParams 分享相关信息，请使用"NSMutableDictionary+GTSDK"中的gt_setupShareParams配置
 */
+ (void)gt_share:(nonnull NSMutableDictionary *)shareParams;


#pragma mark - 推送功能

/**
 @abstract APNS远程推送。用于接收远程通知
 
 @dicussion  已在内部集成
 @dicussion 在应用启动完成后设置代理
 @dicussion 在Appdelegate中是实现代理方法gt_didReceiveRemoteNotification即可接收消息的响应
 */

/**
 @abstract 设置远程通知角标显示数量
 @dicussion 在用户收到远程通知和用户操作远程通知行为调用进行角标的更新
 */
+ (void)gt_setGTNotificationBadgeCount:(NSInteger)count;


#pragma mark - 支付功能
/**
 @abstract      商品支付功能
 @param payParams 支付相关信息，请使用"NSMutableDictionary+GTSDK"中的gt_setupPayParams配置
 */
+ (void)gt_pay:(nonnull NSMutableDictionary *)payParams;


+ (void)gt_getProductsWithSkuIds:(NSSet *_Nonnull)skuIds completionHandler:(void(^)(NSDictionary * _Nullable products))completionHandler;

+ (void)gt_queryCpOrderId:(NSString *)cpOrderId completionHandler:(GTCompletionHandler)completionHandler;


#pragma mark - 客服功能
/**
 @abstract      客服功能
 @param customerParams 客服相关信息，请使用"NSMutableDictionary+GTSDK"中的gt_setupCustomerParams配置
 */
+ (void)gt_customer:(nonnull NSMutableDictionary *)customerParams;


#pragma mark - 用户协议功能
/**
 @abstract      展示用户协议
 @param agreementParams 客服相关信息，请使用"NSMutableDictionary+GTSDK"中的gt_setupAgreementParams配置
 */
+ (void)gt_agreement:(nonnull NSMutableDictionary *)agreementParams;


#pragma mark - 统计功能
/**
 @abstract      事件上传功能
 @param eventTrackParams 支付相关信息，请使用"NSMutableDictionary+GTSDK"中的gt_setupEventTrackParams配置
 */
+ (void)gt_trackEvent:(nonnull NSMutableDictionary *)eventTrackParams;

/**
 @abstract 绑定角色信息
 @param roleParams 角色信息，请使用"NSMutableDictionary+GTSDK"中的gt_setupBindParamsRoleID配置
 */
+ (void)gt_bindRole:(nonnull NSMutableDictionary *)roleParams;


/**
 @abstract 记录传递信息
 @param key 记录上传信息，可用于统计加载统计等
 */
+ (void)gt_reportSdkEventWithKey:(NSString *)key;


/**
 @abstract 记录传递信息
 @paras params 参数字典
 @param eventName 事件名称，可用于统计加载统计等
 */
+ (void)logEvent:(NSDictionary *)params eventName:(NSString *)eventName;


#pragma mark - 评分功能
/**
 @abstract 评分
 @param evaluationParams 请使用"NSMutableDictionary+GTSDK"中的gt_setupEvaluationParamsAppID配置
 */
+ (void)gt_evaluate:(nonnull NSMutableDictionary *)evaluationParams;


#pragma mark - 公告功能
+ (void)gt_announcementCompletionHandler:(void(^)(int code, id _Nullable response))handler;


#pragma mark - 广告功能

#pragma mark - IDFA 授权
/**
 @abstract      iOS14请求idfa权限
 */

/*
0: ATTrackingManagerAuthorizationStatusNotDetermined (授权状态待定):还未弹窗供用户选择
1: ATTrackingManagerAuthorizationStatusRestricted (授权状态受限):手机未打开广告追踪权限，于设置-隐私-追踪设置
2: ATTrackingManagerAuthorizationStatusDenied(已拒绝):已弹窗用户拒绝授权
3: ATTrackingManagerAuthorizationStatusAuthorized(已授权):已弹窗用户同意授权
*/

/**
 @abstract      不包含引导页请求ATT
 */
+ (void)gt_requireATT:(void (^_Nullable)(AppTrackingAuthorizationStatus status))completionHandler;

/**
 @abstract      包含引导页请求ATT
 */

+ (void)requestAppTrackingAuthorizationWithPagesCompletionHandler:(void (^_Nullable)(AppTrackingAuthorizationStatus status))completionHandler;

/**
 @abstract      获取ATT授权状态
 */
+ (int)gt_getATTStatus;


/**
 @abstract      获取是否可以弹出ATT的状态,依据服务器返回状态+ATT状态
 */

+ (void)gt_getATTOpenStatus:(void (^_Nullable)(int attStatus))completionHandler;

#pragma mark - 其他功能

+ (void)setLanguage:(NSString *)language;


/**
 @abstract      上传游戏尾巴
 */
+ (void)gt_uploadGameInfo:(nonnull NSMutableDictionary *)gameParams;



/**
 @abstract      获取设备Id
 @dicussion  保存在钥匙串中的唯一Id。 e.g., "7E764935-24CB-4EE3-B718-2BB2C5BA5A0A".
 */
+ (nonnull NSString *)gt_deveceID;

/**
 @abstract      获取设备Id
 @dicussion  保存在钥匙串中的唯一Id。 e.g., "7E764935-24CB-4EE3-B718-2BB2C5BA5A0A".
 */
+ (nonnull NSString *)gt_deviceId;


/**
 @abstract      获取设备类型
 @dicussion  设备类型。 目前固定为 "ios".
 */
+ (nonnull NSString *)gt_deviceType;


/**
 @abstract      获取平台类型
 @dicussion  平台类型。 e.g., "AppleStore".
 */
+ (nonnull NSString *)gt_platform;


/**
 @abstract      获取系统版本
 @dicussion  系统版本。e.g., "11.4".
 */
+ (nonnull NSString *)gt_deviceOSVersion;


/**
 @abstract      获取设备名称
 @dicussion  获取设备名称。 e.g., "iPhone8,1".
 */
+ (nonnull NSString *)gt_deviceModel;


/**
 @abstract      获取网络类型
 @dicussion  网络类型。 e.g., "WIFI".
 */
+ (nonnull NSString *)gt_getNetwork;


/**
 @abstract      获取系统语言
 @dicussion  系统语言。
 */
+ (nonnull NSString *)getLanguage;



@end

NS_ASSUME_NONNULL_END
