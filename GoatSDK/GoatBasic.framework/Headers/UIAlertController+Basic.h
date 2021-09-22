//
//  UIAlertController+Goat.h
//  GoatUtility
//
//  Created by Choici on 2017/4/14.
//  Copyright ©2019年 Goat. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIAlertController (Goat)

/**
 使用独立的window弹出自己
 */
- (void)bc_show;

/**
 使用独立的window弹出自己
 
 @param animated    是否带动画效果
 */
- (void)bc_show:(BOOL)animated;

/**
 使用独立的window弹出action sheet
 
 @dicussion iPad下会采用pod的形式弹出
 @param sourceView  pop所在的源视图
 @param direction   pop的箭头方向
 */
- (void)bc_showIpadActionSheet:(UIView *)sourceView arrow:(UIPopoverArrowDirection)direction;

@end
