//
//  NSDate+Goat.h
//  GoatUtility
//
//  Created by Choici on 2019/2/3.
//

#import <Foundation/Foundation.h>

@interface NSDate (Basic)

/**
 @description   获取当前时间戳
 */
+ (long)bc_timestampOfNow;
/**
 @description   检测当前Date对象的日期是否已到达或超出相对日期的指定间隔。间隔的年、月、日等为负数时，间隔时间相应按单位加减计算，然后再加上到相对日期，与当前Date对象日期对比。例如：现在是否已经超时1天相对于昨天的登录时间，即[[NSDate date] bc_isTimeoutToReferenceDate:lastLoginDate intervalYears:0 months:0 days:1 hours:0 minutes:0 seconds:0];
 
 @param referenceDate   相对时间
 @param years   间隔的年数
 @param months  间隔的月数
 @param days    间隔的日数
 @param hours   间隔的小时数
 @param minutes 间隔的分钟数
 @param seconds 间隔的秒数
 
 @return 已超时则返回YES，否则返回NO。
 */
- (BOOL)bc_isTimeoutToReferenceDate:(NSDate *)referenceDate
                        intervalYears:(NSInteger)years
                               months:(NSInteger)months
                                 days:(NSInteger)days
                                hours:(NSInteger)hours
                              minutes:(NSInteger)minutes
                              seconds:(NSInteger)seconds;

/**
 @description   获取当前日期（不含年份和月份）
 */
+ (NSString *)bc_dayOfToday;
/**
 @description   获取当前日期时间的格式化结果
 @param format  格式。默认采用yyyy-MM-dd_HH:mm，大写HH为24小时制，_为空格。
 */
+ (NSString *)bc_dateByFormat:(NSString *)format;

@end
