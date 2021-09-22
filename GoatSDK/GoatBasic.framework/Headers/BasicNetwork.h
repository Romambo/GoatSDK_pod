//
//  GoatNetwork.h
//
//
//  Created by choici on 2019/5/28.
//  Copyright © 2019 goatgames. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BasicRequestHeader.h"

typedef NS_ENUM(NSUInteger, BASIC_REQUEST_METHOD) {
    BASIC_REQUEST_METHOD_POST,
    BASIC_REQUEST_METHOD_GET,
};



NS_ASSUME_NONNULL_BEGIN

@interface BasicNetwork : NSObject

+ (void)bc_requestMethod:(BASIC_REQUEST_METHOD)method path:(nonnull NSString *)path headers:(NSMutableDictionary *)headers
           parameters:(nullable NSMutableDictionary<NSString *,NSString *> *)parameters
           completion:(nullable void(^)(int code, id  _Nullable response))completionHandler;

@end

NS_ASSUME_NONNULL_END
