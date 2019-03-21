//
//  NSDate+PJRadio.h
//  PJCategory
//
//  Created by peng xu on 2019/3/21.
//  Copyright © 2019 xupeng. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDate (PJCategory)

#pragma mark - Component Properties

/**
 年
 */
@property (nonatomic, readonly) NSInteger year;

/**
 月 1~12
 */
@property (nonatomic, readonly) NSInteger month;

/**
 日 1~31
 */
@property (nonatomic, readonly) NSInteger day; // < Day component (1~31)

/**
 小时 0~23
 */
@property (nonatomic, readonly) NSInteger hour;

/**
 分钟 0~59
 */
@property (nonatomic, readonly) NSInteger minute;

/**
 秒 0~59
 */
@property (nonatomic, readonly) NSInteger second;

/**
 纳秒
 */
@property (nonatomic, readonly) NSInteger nanosecond;

/**
 周几，第一天和用户设置有关 1~7
 */
@property (nonatomic, readonly) NSInteger weekday;

/**
 weekdayOrdinal
 */
@property (nonatomic, readonly) NSInteger weekdayOrdinal;

/**
 一个月的第几周 1~5
 */
@property (nonatomic, readonly) NSInteger weekOfMonth;

/**
 一年的第几周 1~53
 */
@property (nonatomic, readonly) NSInteger weekOfYear;

/**
 YearForWeekOfYear
 */
@property (nonatomic, readonly) NSInteger yearForWeekOfYear;

/**
 季度
 */
@property (nonatomic, readonly) NSInteger quarter;

/**
 闰月
 */
@property (nonatomic, readonly) BOOL isLeapMonth;

/**
 闰年
 */
@property (nonatomic, readonly) BOOL isLeapYear;

/**
 是否是今天
 */
@property (nonatomic, readonly) BOOL isToday;

/**
 是否是昨天
 */
@property (nonatomic, readonly) BOOL isYesterday; // < Weather date is yesterday (based on current locale)

#pragma mark - Date modify
/**
 通过增加year生成一个新的日期
 */
- (nullable NSDate *)dateByAddingYears:(NSInteger)years;

/**
 通过增加month生成一个新的日期
 */
- (nullable NSDate *)dateByAddingMonths:(NSInteger)months;

/**
 通过增加weeks生成一个新的日期
 */
- (nullable NSDate *)dateByAddingWeeks:(NSInteger)weeks;

/**
 通过增加days生成一个新的日期
 */
- (nullable NSDate *)dateByAddingDays:(NSInteger)days;

/**
 通过增加hours生成一个新的日期
 */
- (nullable NSDate *)dateByAddingHours:(NSInteger)hours;

/**
 通过增加minuts生成一个新的日期
 */
- (nullable NSDate *)dateByAddingMinutes:(NSInteger)minutes;

/**
 通过增加seconds生成一个新的日期
 */
- (nullable NSDate *)dateByAddingSeconds:(NSInteger)seconds;


#pragma mark - Date Format

/**
 根据format返回一个字符串描述
 see http://www.unicode.org/reports/tr35/tr35-31/tr35-dates.html#Date_Format_Patterns
 */
- (nullable NSString *)stringWithFormat:(NSString *)format;

/**
 根据format和locale返回一个字符串描述
 see http://www.unicode.org/reports/tr35/tr35-31/tr35-dates.html#Date_Format_Patterns
 */
- (nullable NSString *)stringWithFormat:(NSString *)format
                               timeZone:(nullable NSTimeZone *)timeZone
                                 locale:(nullable NSLocale *)locale;

/**
 返回一个ISO8601格式的字符串.
 e.g. "2010-07-09T16:13:30+12:00"
*/
- (nullable NSString *)stringWithISOFormat;

/**
 根据字符串和格式生成一个日期
 */
+ (nullable NSDate *)dateWithString:(NSString *)dateString format:(NSString *)format;

/**
 根据字符串和格式生成一个日期
 
 @param dateString 待解析的字符串
 @param format     格式
 @param timeZone   timeZone
 @param locale     locale
 */
+ (nullable NSDate *)dateWithString:(NSString *)dateString
                             format:(NSString *)format
                           timeZone:(nullable NSTimeZone *)timeZone
                             locale:(nullable NSLocale *)locale;

/**
 用ISO8601的格式去解析字符串，生成一个日期
 @param dateString 字符串 e.g. "2010-07-09T16:13:30+12:00"

 */
+ (nullable NSDate *)dateWithISOFormatString:(NSString *)dateString;

/**
 返回格林威治时间的日历
 */
+ (NSCalendar *)defaultCalender;

@end
NS_ASSUME_NONNULL_END
