//
//  BasicViewFromNib.h
//  GoatBasic
//
//  Created by choici o on 2021/2/21.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface BasicViewFromNib : NSObject

/**
  从xib中取控制器
 */
+ (UIViewController *)bc_xibFromClassName:(NSString *)classString resourceName:(NSString *)resourceName typeName:(NSString *)typeName;

/**
  从nib中取视图
 */
+ (UIView *)bc_nibFromClassName:(NSString *)classString resourceName:(NSString *)resourceName typeName:(NSString *)typeName owner:(id)owner;





@end

NS_ASSUME_NONNULL_END
