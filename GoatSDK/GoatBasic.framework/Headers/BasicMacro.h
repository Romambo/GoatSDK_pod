//
//  GoatMacro.h
//  GoatUtility
//
//  Created by Choici on 2019/4/13.
//  Copyright © 2019年 Goat. All rights reserved.
//


#ifndef BasicMacro_h
#define BasicMacro_h

// 设备版本号
#define Basic_MACRO_IS_GREATER_OR_EQUAL_TO_IOS(v) ([[[UIDevice currentDevice] systemVersion] floatValue] >= v)
#define BasicT_MACRO_IS_IOS_9            Basic_MACRO_IS_GREATER_OR_EQUAL_TO_IOS(9.0)

// Device design
#define BA_MACRO_IS_RETINA           ([[UIScreen mainScreen] scale] == 2.0f || [[UIScreen mainScreen] scale] == 3.0f)
#define BA_MACRO_SCREEN_WIDTH        ([[UIScreen mainScreen] bounds].size.width)
#define BA_MACRO_SCREEN_HEIGHT       ([[UIScreen mainScreen] bounds].size.height)
#define BA_MACRO_IS_IPAD             (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define BA_MACRO_IS_IPHONE           (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define BA_MACRO_IS_IPADPRO          (BA_MACRO_IS_IPAD && (BA_MACRO_SCREEN_WIDTH == 1366.0f || BA_MACRO_SCREEN_HEIGHT == 1366.0f))
#define BA_MACRO_IS_IPHONE_4         (BA_MACRO_IS_IPHONE && (BA_MACRO_SCREEN_WIDTH == 480.0f || BA_MACRO_SCREEN_HEIGHT == 480.0f))
#define BA_MACRO_IS_IPHONE_5         (BA_MACRO_IS_IPHONE && (BA_MACRO_SCREEN_WIDTH == 568.0f || BA_MACRO_SCREEN_HEIGHT == 568.0f))
#define BA_MACRO_IS_IPHONE_6         (BA_MACRO_IS_IPHONE && (BA_MACRO_SCREEN_WIDTH == 667.0f || BA_MACRO_SCREEN_HEIGHT == 667.0f))
#define BA_MACRO_IS_IPHONE_6P        (BA_MACRO_IS_IPHONE && (BA_MACRO_SCREEN_WIDTH == 736.0f || BA_MACRO_SCREEN_HEIGHT == 736.0f))
#define BA_MACRO_IS_IPHONE_X         (BA_MACRO_IS_GREATER_OR_EQUAL_TO_IOS(11.0) ? (!UIEdgeInsetsEqualToEdgeInsets([[[UIApplication sharedApplication].keyWindow valueForKey:@"safeAreaInsets"] UIEdgeInsetsValue], UIEdgeInsetsZero)) : NO)

//根据设备返回设定值 IPAD_IPADPRO_IP4_IP5_IP6_IP6P_IPX
#define BA_MACRO_RETURN_SIZE_IPAD_IPADPRO_IP4_IP5_IP6_IP6P_IPX(iPad, iPadPro, iPhone4, iPhone5, iPhone6, iPhone6P, iPhoneX) \
( BA_MACRO_IS_IPHONE_4 ? iPhone4 : ( BA_MACRO_RETURN_SIZE_IPAD_IPADPRO_IP5_IP6_IP6P_IPX(iPad, iPadPro, iPhone5, iPhone6, iPhone6P, iPhoneX)) )
//不包含 iPhone4
#define BA_MACRO_RETURN_SIZE_IPAD_IPADPRO_IP5_IP6_IP6P_IPX(iPad, iPadPro, iPhone5, iPhone6, iPhone6P, iPhoneX) \
( BA_MACRO_IS_IPAD ? ( BA_MACRO_IS_IPADPRO ? iPadPro : iPad) : (BA_MACRO_IS_IPHONE_X ? iPhoneX : ( BA_MACRO_IS_IPHONE_6P ? iPhone6P : (BA_MACRO_IS_IPHONE_6 ? iPhone6 : (BA_MACRO_IS_IPHONE_5 ? iPhone5 : iPhone6)))))

//设备方向
#define BA_MACRO_IsPortrait(orientation)           ((orientation) == UIDeviceOrientationPortrait || (orientation) == UIDeviceOrientationPortraitUpsideDown)
#define BA_MACRO_IsLandscape(orientation)          ((orientation) == UIDeviceOrientationLandscapeLeft || (orientation) == UIDeviceOrientationLandscapeRight)

// Color
#define BA_MACRO_COLOR_RGB (r,g,b)                (BA_MACRO_COLOR_RGBA(r,g,b,1.0))
#define BA_MACRO_COLOR_RGBA(r,g,b,a)              ([UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:a])
// rgb颜色转换（16进制->10进制）
#define BA_MACRO_COLOR_HexCOLOR(rgbValue)         ([UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0f green:((float)((rgbValue & 0xFF00) >> 8))/255.0f blue:((float)(rgbValue & 0xFF))/255.0f alpha:1.0])
// 随机色
#define BA_MACRO_COLOR_RANDOM                     ([UIColor colorWithRed:arc4random_uniform(256)/255.0f green:arc4random_uniform(256)/255.0f blue:arc4random_uniform(256)/255.0f alpha:1.0])

/**
 Synthsize a dynamic object property in @implementation scope.
 It allows us to add custom properties to existing classes in categories.
 
 @param association  ASSIGN / RETAIN / COPY / RETAIN_NONATOMIC / COPY_NONATOMIC
 @warning #import <objc/runtime.h>
 *******************************************************************************
 Example:
 @interface NSObject (MyAdd)
 @property (nonatomic, strong) UIColor *myColor;
 @end
 
 #import <objc/runtime.h>
 @implementation NSObject (MyAdd)
 EFSYNTH_DYNAMIC_PROPERTY_OBJECT(myColor, setMyColor, RETAIN, UIColor *)
 @end
 */
#ifndef BASYNTH_DYNAMIC_PROPERTY_OBJECT
#define BASYNTH_DYNAMIC_PROPERTY_OBJECT(_getter_, _setter_, _association_, _type_) \
- (void)_setter_ : (_type_)object { \
[self willChangeValueForKey:@#_getter_]; \
objc_setAssociatedObject(self, _cmd, object, OBJC_ASSOCIATION_ ## _association_); \
[self didChangeValueForKey:@#_getter_]; \
} \
- (_type_)_getter_ { \
return objc_getAssociatedObject(self, @selector(_setter_:)); \
}
#endif

/**
 Add this macro before each category implementation, so we don't have to use
 -all_load or -force_load to load object files from static libraries that only
 contain categories and no classes.
 More info: http://developer.apple.com/library/mac/#qa/qa2006/qa1490.html .
 *******************************************************************************
 Example:
 EFSYNTH_DUMMY_CLASS(NSString_YYAdd)
 */
#ifndef BASYNTH_DUMMY_CLASS
#define BASYNTH_DUMMY_CLASS(_name_) \
@interface BASYNTH_DUMMY_CLASS_ ## _name_ : NSObject @end \
@implementation BASYNTH_DUMMY_CLASS_ ## _name_ @end
#endif


/**
 detect empty (nil) arguments of function. Don't have to and can't add nil or [NSNull null] at trail of macro argument.
 source info: https://gustedt.wordpress.com/2010/06/08/detect-empty-macro-arguments/
 *******************************************************************************
 
 */
#define BA_MACRO_MISSING_PARAMS_ALERT(message_, ...) \
efunCheckParams((^{ \
[BasicAlertView showAlertViewWithTitle:@"提示" message:message_ completion:nil buttonTitles:@"OK", nil]; \
}), NO, __VA_ARGS__, [NSNull null])

#define BA_MACRO_MISSING_PARAMS_ASSERT(message_, ...) \
efunCheckParams((^{ \
NSAssert(NO, message_); \
}), YES, __VA_ARGS__, [NSNull null])

#define BA_MACRO_MISSING_PARAMS_LOG(message_, ...) \
efunCheckParams((^{ \
EF_LOG_DIRECTLY(message_); \
}), NO, __VA_ARGS__, [NSNull null])

#endif /* GoatMacro_h */



#pragma mark -------------weakify-----------------


#ifndef weakify
    #if DEBUG
        #if __has_feature(objc_arc)
            #define weakify(object) autoreleasepool{} __weak __typeof__(object) weak##_##object = object;
        #else
            #define weakify(object) autoreleasepool{} __block __typeof__(object) block##_##object = object;
        #endif
    #else
        #if __has_feature(objc_arc)
            #define weakify(object) try{} @finally{} {} __weak __typeof__(object) weak##_##object = object;
        #else
            #define weakify(object) try{} @finally{} {} __block __typeof__(object) block##_##object = object;
        #endif
    #endif
#endif


#pragma mark -------------strongify-----------------

#ifndef strongify
    #if DEBUG
        #if __has_feature(objc_arc)
            #define strongify(object) autoreleasepool{} __typeof__(object) object = weak##_##object;
        #else
            #define strongify(object) autoreleasepool{} __typeof__(object) object = block##_##object;
        #endif
    #else
        #if __has_feature(objc_arc)
            #define strongify(object) try{} @finally{} __typeof__(object) object = weak##_##object;
        #else
            #define strongify(object) try{} @finally{} __typeof__(object) object = block##_##object;
        #endif
    #endif
#endif


