//
//  GoatFileManager.h
//  GoatUtility
//
//  Created by HTC on 2019/1/15.
//  Copyright © 2019年 Goat. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 文件管理工具
 */
@interface BasicFileManager : NSObject


/**
 获取在mainBundle中文件的全路径
 
 @param fileFullName 文件全名，包含后缀
 @return 返回路径，找不到时返回 nil
 */
+ (NSString *)bc_filePathInMainbundle:(NSString *)fileFullName;


/**
 获取在bundle图片的全路径
 
 @param bundleName 文件全名，包含后缀
 @param imgName 图片名称，包含后缀
 @return 返回路径，找不到时返回 nil
 */
+ (NSString *)bc_imgPathBundleName:(NSString *)bundleName imgName:(NSString *)imgName;

/**
 判断一个文件是否存在当前文件路径下
 
 @param filePath 文件绝对路径
 @return YES or NO
 */
+ (BOOL)bc_isFileExistAtPath:(NSString *)filePath;

/**
 判断一个文件是否存在mainBundle中
 
 @param fileFullName 文件全名，包含后缀
 @return YES or NO
 */
+ (BOOL)bc_isFileExistInMainbundle:(NSString *)fileFullName;



/**
 获取plist文件内容转换为数组
 
 @param filePath 文件绝对路径
 @return 数组，如果没有就返回空数组
 */
+ (NSArray *)bc_arrayWithContentsOfPlistFilePathAtPath:(NSString *)filePath;

/**
 获取plist文件内容转换为数组
 
 @param fileFullName plist文件全名，包含后缀【mainBundle中】
 @return 数组，如果没有就返回空数组
 */
+ (NSArray *)bc_arrayWithContentsOfPlistFile:(NSString *)fileFullName;



/**
 获取plist文件内容转换为字典
 
 @param filePath 文件绝对路径
 @return 字典，如果没有就返回空字典
 */
+ (NSDictionary *)bc_dictionaryWithContentsOfPlistFileAtPath:(NSString *)filePath;

/**
 获取plist文件内容转换为字典
 
 @param fileFullName plist文件全名，包含后缀【mainBundle中】
 @return 字典，如果没有就返回空字典
 */
+ (NSDictionary *)bc_dictionaryWithContentsOfPlistFile:(NSString *)fileFullName;


/**
 获取json文件内容转换为字典
 
 @param filePath 文件绝对路径
 @return 字典，如果没有就返回空字典
 */
+ (NSDictionary *)bc_dictionaryWithContentsOfJosnFileAtPath:(NSString *)filePath;

/**
 获取json文件内容转换为字典
 
 @param fileFullName json文件全名，包含后缀【mainBundle中】
 @return 字典，如果没有就返回空字典
 */
+ (NSDictionary *)bc_dictionaryWithContentsOfJosnFile:(NSString *)fileFullName;


+ (NSDictionary *)bc_tabDictionaryWithContentsOfJosnFile:(NSString *)fileFullName;

@end
