//
//  NSDictionary+Goat.h
//
//
//  Created by Choici on 2021/2/4
//  Copyright © 2019年 Goat. All rights reserved.
//

#import <Foundation/Foundation.h>

FOUNDATION_EXPORT NSString *const basic_dictionary_key_status;//状态，成功or失败
FOUNDATION_EXPORT NSString *const basic_dictionary_key_message;//状态信息
FOUNDATION_EXPORT NSString *const basic_dictionary_key_errorCode;//错误码

@interface NSDictionary (Basic)

#pragma mark - Goat Dictionary set/get
- (id)bc_safeObjectForKey:(NSString *)key;
- (void)bc_safeSetObject:(id)object forKey:(id)key;
- (id)bc_safeKeyForValue:(id)value;
- (NSString *)bc_toJSONStringForDictionary;








#pragma mark - Goat Dictionary append
// 用于便利封装键值对的字典
/*
   使用方法举例： NSDictionary.gt_append(@"appendKey", @"appendValue");
 */
+ (NSDictionary *(^)(NSString * key, id value))bc_append;
- (NSDictionary *(^)(NSString * key, id value))bc_append;

// 使用方法举例：NSDictionary *resultDic = NSDictionary.gt_status_message(@"status:YES/NO", @"message:XXX");
//            NSDictionary *appendInfo = resultDic.gt_errorCode(@"404");
//
+ (NSDictionary *(^)(id statusValue, id messageValue))bc_status_message;
- (NSDictionary *(^)(id value))bc_status;
- (NSDictionary *(^)(id value))bc_message;
- (NSDictionary *(^)(id value))bc_errorCode;

/**
 *  获取efun封装的字典值方法
 */
- (id)bc_objectOfStatus;
- (id)bc_objectOfMessage;
- (id)bc_objectOfErrorCode;

#pragma mark - lowercaseKeys
/*
 Recursive algorithm to find all nested dictionary keys and create an NSMutableDictionary copy with all keys converted to lowercase.
 Returns an NSMutableDictionary with all keys and nested keys converted to lowercase.
 */
+ (NSMutableDictionary *)bc_dictionaryWithLowercaseKeysFromDictionary:(NSDictionary *)dictionary;

/*
 Convienience method to create a new lowercase dictionary object an existing NSDictionary instance
 Returns an NSMutableDictionary with all keys and nested keys converted to lowercase.
 */
- (NSMutableDictionary *)bc_dictionaryWithLowercaseKeys;


#pragma mark - uppercaseKey
/*
 Recursive algorithm to find all nested dictionary keys and create an NSMutableDictionary copy with all keys converted to uppercase.
 Returns an NSMutableDictionary with all keys and nested keys converted to uppercase.
 */
+ (NSMutableDictionary *)bc_dictionaryWithUppercaseKeysFromDictionary:(NSDictionary *)dictionary;

/*
 Convienience method to create a new uppercase dictionary object an existing NSDictionary instance
 Returns an NSMutableDictionary with all keys and nested keys converted to uppercase.
 */
- (NSMutableDictionary *)bc_dictionaryWithUppercaseKeys;


@end
