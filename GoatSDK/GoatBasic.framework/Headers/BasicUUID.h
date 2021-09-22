//
//  GTUUID.h
//  GTSDK
//
//  Created by choici on 2019/4/29.
//  Copyright © 2019 Goat Games. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BasicUUID : NSObject

+ (NSString *)bc_UUID;

//测试用
+ (BOOL)bctest_resetUUID;

@end

NS_ASSUME_NONNULL_END
