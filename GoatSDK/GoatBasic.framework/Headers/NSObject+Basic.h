//
//  NSObject+Goat.h
//  Pods
//
//  Created by Choici on 2019/6/11.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface NSObject (Basic)
//校验请求结果
- (BOOL)bc_successfull:(id  _Nullable)response success:(BOOL)success;

//获取内部静态库xib路径
- (UIViewController *_Nullable)bc_pathFrameworkXibClass:(NSString *_Nonnull)classtr;

//验证邮箱
- (BOOL)bc_validationEmail:(NSString *_Nonnull)email;

//json转字典
- (NSDictionary *_Nullable)bc_dictionaryWithJsonString:(NSString *_Nonnull)jsonString;

//字典转json
- (NSString *_Nullable)bc_jsonStringWithDict:(NSDictionary *_Nonnull)dict;

//json转数组
- (id _Nullable )bc_arrayWithJsonString:(NSString *_Nonnull)jsonString;

//数组转json
- (NSString *_Nullable)bc_arrayToJsonString:(NSArray *_Nonnull)array;


@end
