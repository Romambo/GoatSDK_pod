//
//  GoatBasicPublic.h
//  GoatBasic
//
//  Created by choici o on 2021/3/16.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN

@interface BasicToast : NSObject

+ (void)bc_toastShowMessage:(NSString *)message onView:(UIView *)superView;

+ (void)bc_loadingShowing;

+ (void)bc_loadingDismissing;

+ (void)bc_loadingDismissWhenDelay:(NSTimeInterval)delay;

+ (NSString *)bc_jsonStringFromDict:(NSDictionary *)dict;




@end

NS_ASSUME_NONNULL_END
