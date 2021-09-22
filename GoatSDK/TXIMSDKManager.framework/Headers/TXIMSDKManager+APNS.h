//
//  TXIMSDKManager+APNS.h
//  TXIMSDKManager
//
//  Created by Adminstration on 2021/6/15.
//

#import "TXIMSDKManager.h"
#import <ImSDK_Plus/V2TIMManager+APNS.h>


NS_ASSUME_NONNULL_BEGIN

@interface TXIMSDKManager (APNS)

/////////////////////////////////////////////////////////////////////////////////
//
//                         设置 APNS 推送
//
/////////////////////////////////////////////////////////////////////////////////
/**
 *  1.1 设置 APNS 监听
 */
- (void)setAPNSListener:(id<V2TIMAPNSListener>)apnsListener;

/**
 *  1.2 设置 APNS 推送
 *
 *  config -> token：苹果后台对客户端的唯一标识，需要主动调用系统 API 获取,获取方法如下:
 *
 *  <pre>
 *  //获取 token 代码示例
 *  if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0) {
 *    [[UIApplication sharedApplication] registerUserNotificationSettings:
 *        [UIUserNotificationSettings settingsForTypes:
 *            (UIUserNotificationTypeSound | UIUserNotificationTypeAlert | UIUserNotificationTypeBadge) categories:nil]];
 *    [[UIApplication sharedApplication] registerForRemoteNotifications];
 *  }
 *  else{
 *    [[UIApplication sharedApplication] registerForRemoteNotificationTypes:
 *        (UIUserNotificationTypeBadge | UIUserNotificationTypeSound | UIUserNotificationTypeAlert)];
 *  }
 *
 *  //收到 token 代码示例
 *  -(void)application:(UIApplication *)app didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
 *    //回调的 deviceToken 就是需要的 token 信息
 *  }
 *  </pre>
 *
 *  config -> busiId：推送证书 ID，上传推送证书（p.12）到 IM 控制台后生成。
 *  具体步骤请参考 [离线推送](https://cloud.tencent.com/document/product/269/9154)。
 *
 *  @note
 *  - 接口成功设置后会开启离线推送功能，如果您需要自定义推送的格式信息，请参考 V2TIMManager+Message.h 里面的 sendMessage 接口。
 *  - 如果成功开启了离线推送，APP 进后台后，如果收到消息，会弹系统推送通知，APP 进前台后，如果收到消息，则不会弹系统推送通知。
 *  - APP 进后台后应用图标展示的未读数默认为所有会话未读数之和,如果您需要自定义 APP 的未读数，请监听 V2TIMAPNSListener 回调设置。
 */
- (void)setAPNS:(V2TIMAPNSConfig*)config succ:(V2TIMSucc)succ fail:(V2TIMFail)fail;

@end

NS_ASSUME_NONNULL_END
