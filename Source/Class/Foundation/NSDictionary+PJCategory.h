//
//  NSDictionary+PJCategory.h
//  PJCategory
//
//  Created by peng xu on 2019/3/21.
//  Copyright © 2019 xupeng. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDictionary (ParseKeys)

- (BOOL)boolValueForKey:(NSString *)key default:(BOOL)def;

- (char)charValueForKey:(NSString *)key default:(char)def;

- (unsigned char)unsignedCharValueForKey:(NSString *)key default:(unsigned char)def;

- (short)shortValueForKey:(NSString *)key default:(short)def;

- (unsigned short)unsignedShortValueForKey:(NSString *)key default:(unsigned short)def;

- (int)intValueForKey:(NSString *)key default:(int)def;

- (unsigned int)unsignedIntValueForKey:(NSString *)key default:(unsigned int)def;

- (long)longValueForKey:(NSString *)key default:(long)def;

- (unsigned long)unsignedLongValueForKey:(NSString *)key default:(unsigned long)def;

- (long long)longLongValueForKey:(NSString *)key default:(long long)def;

- (unsigned long long)unsignedLongLongValueForKey:(NSString *)key default:(unsigned long long)def;

- (float)floatValueForKey:(NSString *)key default:(float)def;

- (double)doubleValueForKey:(NSString *)key default:(double)def;

- (NSInteger)integerValueForKey:(NSString *)key default:(NSInteger)def;

- (NSUInteger)unsignedIntegerValueForKey:(NSString *)key default:(NSUInteger)def;

- (nullable NSNumber *)numberValueForKey:(NSString *)key default:(nullable NSNumber *)def;

- (nullable NSString *)stringValueForKey:(NSString *)key;

- (nullable NSString *)stringValueForKey:(NSString *)key default:(nullable NSString *)def;

- (nullable NSString *)intStringForKey:(NSString *)key default:(nullable NSString *)def;

- (nullable NSArray *)arrayValueForKey:(NSString *)key;

- (nullable NSArray *)arrayValueForKey:(NSString *)key default:(nullable NSArray *)def;

- (nullable NSDictionary *)dictionaryValueForKey:(NSString *)key;

- (nullable NSDictionary *)dictionaryValueForKey:(NSString *)key default:(nullable NSDictionary *)def;

@end



@interface NSDictionary(PJCategory)

/**
 转成JSON字符串，非PrettyPrinted
 */
- (nullable NSString *)jsonStringEncoded;

/**
 转成JSON字符串，PrettyPrinted
 */
- (nullable NSString *)jsonPrettyStringEncoded;

/**
 排序好的Keys
 */
- (NSArray *)allKeysSorted;

/**
 根据Keys排序包的Values
 */
- (NSArray *)allValuesSortedByKeys;


@end


@interface NSMutableDictionary<KeyType, ObjectType>(PJCategory)

/**
 安全的设置值，如果key或value无效的话，那么这个方法不会有任何作用
 */
- (void)safeSetObject:(ObjectType)object forKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
