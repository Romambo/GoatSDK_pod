//
//  EFSystemConfiguration.h
//  EfunUtility
//
//  Created by Choici on 2019/3/28.
//  Copyright © 2019年 Goat. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BasicSystemConfiguration : NSObject

/**
 @description   获取证书中的开发者团队ID
 */
+ (NSString *)bc_bundleSeedID;
/**
 @description   获取app包的名称
 */
+ (NSString *)bc_bundleName;
/**
 @description   获取bundle ID
 */
+ (NSString *)bc_bundleIdentifier;
/**
 @description   获取包正式版本
 */
+ (NSString *)bc_bundleShortVersionString;
/**
 @description   获取包构建版本
 */
+ (NSString *)bc_bundleVersion;
/**
 @description   获取操作系统版本
 */
+ (NSString *)bc_systemVersion;
/**
 @description   获取设备型号（设备型号的代号）
 */
+ (NSString *)bc_deviceModel;
/**
 @description   获取广告追踪ID
 */
+ (NSString *)bc_idfa;
/**
 @description   获取应用开发商标识符
 */
+ (NSString *)bc_idfv;
/**
 @description   获取UUID
 */
+ (NSString *)bc_uuid;
/**
 @description   是否允许使用广告追踪ID
 */
+ (BOOL)bc_isIdfaEnabled;
/**
 @description   获取IP地址
 */
+ (NSString *)bc_ip;
/**
 @description   获取MAC地址
 */
+ (NSString *)bc_mac;
/**
 @description   获取系统当前设置的语言
 */
+ (NSString*)bc_language;
/**
 @description   获取设备当前的IMSI，其由MCC和MNC两部分组成。
 @discussion    当没有sim卡或者关闭微蜂窝时返回nil。MCC(Mobile Country Code
 移动国家码)的资源由国际电联(ITU)统一分配，唯一识别移动用户所属的国家，MCC共3位，例如中国地区的MCC为460。MNC(Mobile Network Code 移动网络号码)，用于识别移动客户所属的移动网络运营商，例如中国移动MNC为00、02、07，中国联通的MNC为01、06、09，中国电信的MNC为03、05、11.
 */
+ (NSString *)bc_imsi;

/**
 @description   设备的当前网络连接使用的技术标识
 */
+ (NSString *)bc_networkAccessTechnology;

/**
 网络连接状态类型

 - EFSystemNetworkNotReachable: 无连接
 - EFSystemNetworkUnknown: 未知连接
 - EFSystemNetworkWifi: Wifi连接
 - EFSystemNetwork2G: 2G连接
 - EFSystemNetwork3G: 3G连接
 - EFSystemNetwork4G: 4G连接
 */
typedef NS_ENUM(NSUInteger,BASystemNetworkStatusType) {
    BASystemNetworkNotReachable,
    BASystemNetworkUnknown,
    BASystemNetworkWifi,
    BASystemNetwork2G,
    BASystemNetwork3G,
    BASystemNetwork4G,
};

/**
 获取设备当前网络状态类型

 @param hostName 用于测试状态的依据域名
 @return 网络状态类型
 */
+ (NSString *)bc_networkStatusWithHostName:(NSString *)hostName;

@end
