//
//  GoatRequestHeader.h
//  GoatBasic
//
//  Created by choici o on 2021/1/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString *const BC_HEADER_KEY_GAME_ID;
FOUNDATION_EXPORT NSString *const BC_HEADER_KEY_SDK_VERSION;
FOUNDATION_EXPORT NSString *const BC_HEADER_KEY_ADJ_ID;
FOUNDATION_EXPORT NSString *const BC_HEADER_KEY_AUTH;
FOUNDATION_EXPORT NSString *const BC_HEADER_KEY_UUID;
FOUNDATION_EXPORT NSString *const BC_HEADER_KEY_LANGUAGE;

@interface BasicRequestHeader : NSObject

/**
 "gameId"，外部传入，必选
 "deviceId"，efun外部传入，必选
 "sdkVersion"，外部传入，必选
 "ip" ，外部传入，可选
 "authorization" ，外部传入，可选
 "adjustId"，外部传入，可选
 
 "timestamp"，SDK获取
 "appId" ，SDK获取
 "deviceType" ，SDK获取
 "idfa"，SDK获取
 "idfv" ，SDK获取
 "deviceOsVersion" ，SDK获取
 "deviceName"，SDK获取
 "platform" ，SDK获取
 "language" ，SDK获取
 "appVersion"，SDK获取
 "sign"，SDK获取
 */
/**
 
 获取到服务器时间戳以后调用
 tms：服务器时间戳字符串
 */
+ (void)bc_timestampDifWithServerTMS:(NSString *)tms;

+ (NSMutableDictionary *)bc_headersWithElements:(NSDictionary *_Nullable)elements;


@end

NS_ASSUME_NONNULL_END
