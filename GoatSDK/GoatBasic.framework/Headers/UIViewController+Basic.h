//
//  UIViewController+Goat.h
//  GoatUtility
//
//  Created by Choici on 2017/4/1.
//  Copyright ©2019年 Goat. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIViewController (Basic)

/**
 返回当前viewController上嵌套present的顶层viewController
 */
- (UIViewController *)bc_topPresentedViewController;

/**
 返回当前主window的根viewController
 */
+ (UIViewController *)bc_rootViewController;

@end
