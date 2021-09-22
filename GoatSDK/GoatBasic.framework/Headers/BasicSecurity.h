//
//  EFSecurity.h
//  EfunUtility
//
//  Created by Choici on 2019/4/14.
//  Copyright © 2019年 Goat. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BasicSecurity : NSObject

+ (NSString *)bc_configurationEncryptOriginalString:(NSString *)originalString;

+ (NSString *)bc_configurationDecryptSecureString:(NSString *)secureString;

@end
