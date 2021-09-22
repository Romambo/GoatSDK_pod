//
//  NSString+Goat.h
//  GoatUtility
//
//  Created by Choici on 2019/3/26.
//  Copyright © 2019年 Goat. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface NSString (Basic)

#pragma mark - Hash
/**
 @description   返回大写的MD5 hash
 */
- (NSString *)bc_md5String;

#pragma mark - Encode & Decode
/**
 @description   返回base64编码后的字符串
 */
- (NSString *)bc_base64EncodedString;

/**
 @description   返回base64解码后的字符串
 */
- (NSString *)bc_stringWithBase64EncodedString;

/**
 @description   返回URL编码后的字符串
 */
- (NSString *)bc_URLEncodedString;

/**
 @description   返回URL解码后的字符串
 */
- (NSString *)bc_URLDecodedString;

/**
 @description   返回RSA加密后的字符串
 */
- (NSString *)bc_rsaEncryptWithPublicKey:(NSString *)publicKey;

/**
 @description   返回RSA解密后的字符串
 */
- (NSString *)bc_rsaDecryptWithPublicKey:(NSString *)publicKey;

/**
 @description   返回RSA解密后的字符串
 */
- (NSString *)bc_rsaDecryptWithPriviteKey:(NSString *)priviteKey;


#pragma mark - Editting

/**
 @description   返回使用“.”代替源字符串前三位和后三位字符中间的字符的字符
 */
- (NSString *)bc_stringByMixingPointFromAndTo:(int)startAndEndLocation;

/**
 @description   返回fromString之后的所有字符
 */
- (NSString *)bc_substringFromTailOfString:(NSString *)fromString;

/**
 @description   返回toString之前的所有字符（源string中反向查找toString）
 */
- (NSString*)bc_substringToHeadOfString:(NSString *)toString;

/**
 @description   返回toString之前的所有字符（自定义查找选项）
 */
- (NSString*)bc_substringToString:(NSString *)toString option:(NSStringCompareOptions)option;

/**
 @description   返回移除字符前后的空字符后的字符串
 */
- (NSString *)bc_stringByTrim;

/**
 @description   判断是否包含某字符串
 */
- (BOOL)bc_hasString:(NSString *)searchString;

/**
 @description   返回包含某字符串的次数
 */
- (int)bc_timesOfString:(NSString *)searchString;

/**
 @description   将query格式的字符串转换为NSDicitonary
 */
- (NSDictionary *)bc_componentsSeparatedToKeyValues;

/**
 @description   格式化scale式文件名命名
 */
- (NSString *)bc_stringByAppendingNameScale:(CGFloat)scale;

/**
 @description   格式化scale式路径命名
 */
- (NSString *)bc_stringByAppendingPathScale:(CGFloat)scale;

/**
 @description   获取格式为URL的字符串中的指定key的value的字符串
 */
- (NSString *)bc_substringValueOfURLParameterForKey:(NSString *)key;

#pragma mark - Drawing
/**
 @description   获取字符串的大小
 @param font    字体样式
 @param size    字体大小
 @param lineBreakMode   换行模式
 */
- (CGSize)bc_sizeForFont:(UIFont *)font size:(CGSize)size mode:(NSLineBreakMode)lineBreakMode;

#pragma mark - Regular Expression
/**
 @description   判断是否符合某正则表达式
 @param options 正则表达式选项
 */
- (BOOL)bc_matchesRegex:(NSString *)regex options:(NSRegularExpressionOptions)options;

#pragma mark - Add
/**
 @description   获取UUID
 */
+ (NSString *)bc_stringWithUUID;

- (NSString *)bc_humpTranslateTo_;

- (NSString *)bc__TranslateToHump;


@end
