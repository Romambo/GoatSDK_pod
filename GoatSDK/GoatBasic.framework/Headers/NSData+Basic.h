//
//  NSData+Goat.h
//  GoatUtility
//
//  Created by Choici on 2019/3/26.
//  Copyright © 2019年 Goat. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData (Basic)

/**
 @description   获取data base64编码后的字符串
 */
- (NSString *)bc_base64EncodedString;

/**
 @description   获取字符串 base64解码后的data
 
 @param base64EncodedString base64编码后的字符串
 */
+ (NSData *)bc_dataWithBase64EncodedString:(NSString *)base64EncodedString;

/**
 @description   字节流转换为十六进制显示的字符串
 */
- (NSString *)bc_hexString;

/**
 @description   获取AES256加密后的data
 
 @param key 加密key
 @param iv  加密iv
 */
- (NSData *)bc_aes256EncryptWithKey:(NSString *)key iv:(NSString *)iv;

/**
 @description   获取AES256解密后的data
 
 @param key 解密key
 @param iv  解密iv
 */
- (NSData *)bc_aes256DecryptWithKey:(NSString *)key iv:(NSString *)iv;

/**
 @description   获取RSA加密后的data。注意：内部不含对源data作base64的转码再加密。
 
 @param publicKey 公共key
 */
- (NSData *)bc_rsaEncryptWithPublicKey:(NSString *)publicKey;

/**
 @description   获取RSA解密后的data。注意：内部不含对解密后的data作base64的解码。
 
 @param publicKey 公共key
 */
- (NSData *)bc_rsaDecryptWithPublicKey:(NSString *)publicKey;

/**
 @description   获取RSA解密后的data。注意：内部不含对解密后的data作base64的解码。
 
 @param privateKey 私有key
 */
- (NSData *)bc_rsaDecryptWithPrivateKey:(NSString *)privateKey;

/**
 @description   获取3DES加密后的data
 
 @param key 加密key
 @param iv  加密iv
 */
- (NSData *)bc_3desEncryptWithKey:(NSString *)key iv:(NSString *)iv;

/**
 @description   获取3DES解密后的data
 
 @param key 解密key
 @param iv  解密iv
 */
- (NSData *)bc_3desDecryptWithKey:(NSString *)key iv:(NSString *)iv;
@end
