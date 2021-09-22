//
//  UIDevice+Goat.h
//  Pods
//
//  Created by Choici on 2019/4/19.
//
//

#import <UIKit/UIKit.h>

@interface UIDevice (Basic)

// CPU总数目
- (NSUInteger)bc_getCPUCount;

// 系统总内存空间
- (int64_t)bc_getTotalMemory;



/**
 是否iPad
 */
- (BOOL)bc_isPad;

/**
 是否模拟器
 */
- (BOOL)bc_isSimulator;

/**
 是否越狱机
 */
- (BOOL)bc_isJailbroken;

/**
 设备型号
 */
- (NSString *)bc_machineModel;

/**
 设备型号对应的名称
 */
- (NSString *)bc_machineModelName;

@end
