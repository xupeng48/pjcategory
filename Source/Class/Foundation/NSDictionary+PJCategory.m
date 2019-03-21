//
//  NSDictionary+PJCategory.m
//  PJCategory
//
//  Created by peng xu on 2019/3/21.
//  Copyright © 2019 xupeng. All rights reserved.
//

#import "NSDictionary+PJCategory.h"
#import "NSNumber+PJCategory.h"

#define RETURN_SEL(_sel_) \
if (!key) {\
    return def;\
}\
id value = [self objectForKey:key]; \
if (!value || value == [NSNull null]) { \
    return def; \
}\
if ([value isKindOfClass:[NSNumber class]]) { \
    return [value _sel_]; \
} \
if ([value isKindOfClass:[NSString class]]) { \
    return [value _sel_]; \
} \
return def;


@implementation NSDictionary (ParseKeys)

- (BOOL)boolValueForKey:(NSString *)key default:(BOOL)def {
    RETURN_SEL(boolValue);
}

- (char)charValueForKey:(NSString *)key default:(char)def {
    RETURN_SEL(charValue);
}

- (unsigned char)unsignedCharValueForKey:(NSString *)key default:(unsigned char)def {
    RETURN_SEL(unsignedCharValue);
}

- (short)shortValueForKey:(NSString *)key default:(short)def {
    RETURN_SEL(shortValue);
}

- (unsigned short)unsignedShortValueForKey:(NSString *)key default:(unsigned short)def {
    RETURN_SEL(unsignedShortValue);
}

- (int)intValueForKey:(NSString *)key default:(int)def {
    RETURN_SEL(intValue);
}

- (unsigned int)unsignedIntValueForKey:(NSString *)key default:(unsigned int)def {
    RETURN_SEL(unsignedIntValue);
}

- (long)longValueForKey:(NSString *)key default:(long)def {
    RETURN_SEL(longValue);
}

- (unsigned long)unsignedLongValueForKey:(NSString *)key default:(unsigned long)def {
    RETURN_SEL(unsignedLongValue);
}

- (long long)longLongValueForKey:(NSString *)key default:(long long)def {
    RETURN_SEL(longLongValue);
}

- (unsigned long long)unsignedLongLongValueForKey:(NSString *)key default:(unsigned long long)def {
    RETURN_SEL(unsignedLongLongValue);
}

- (float)floatValueForKey:(NSString *)key default:(float)def {
    RETURN_SEL(floatValue);
}

- (double)doubleValueForKey:(NSString *)key default:(double)def {
    RETURN_SEL(doubleValue);
}

- (NSInteger)integerValueForKey:(NSString *)key default:(NSInteger)def {
    RETURN_SEL(integerValue);
}

- (NSUInteger)unsignedIntegerValueForKey:(NSString *)key default:(NSUInteger)def {
    RETURN_SEL(unsignedIntegerValue);
}

- (nullable NSString *)intStringForKey:(NSString *)key default:(nullable NSString *)def{
    NSNumber * num = [self numberValueForKey:key default:nil];
    if (!num) {
        return def;
    }
    return num.stringValue;
}

- (NSNumber *)numberValueForKey:(NSString *)key default:(NSNumber *)def {
    if (!key) return def;
    id value = self[key];
    if (!value || value == [NSNull null]) return def;
    if ([value isKindOfClass:[NSNumber class]]) return value;
    if ([value isKindOfClass:[NSString class]]) return [NSNumber numberWithString:value];
    return def;
}

- (NSString *)stringValueForKey:(NSString *)key{
    return [self stringValueForKey:key default:nil];
}

- (NSString *)stringValueForKey:(NSString *)key default:(NSString *)def {
    if (!key) return def;
    id value = self[key];
    if (!value || value == [NSNull null]) return def;
    if ([value isKindOfClass:[NSString class]]) return value;
    if ([value isKindOfClass:[NSNumber class]]) return ((NSNumber *)value).description;
    return def;
}

- (nullable NSArray *)arrayValueForKey:(NSString *)key{
    return [self arrayValueForKey:key default:nil];
}

- (nullable NSArray *)arrayValueForKey:(NSString *)key default:(nullable NSArray *)def{
    if (!key) return def;
    id value = self[key];
    if (!value || value == [NSNull null]) return def;
    if ([value isKindOfClass:[NSArray class]]) return value;
    return def;
}

- (nullable NSDictionary *)dictionaryValueForKey:(NSString *)key{
    return [self dictionaryValueForKey:key default:nil];
}

- (nullable NSDictionary *)dictionaryValueForKey:(NSString *)key default:(nullable NSDictionary *)def{
    if (!key) return def;
    id value = self[key];
    if (!value || value == [NSNull null]) return def;
    if ([value isKindOfClass:[NSDictionary class]]) return value;
    return def;
}

@end

@implementation NSDictionary(PJCategory)

- (NSString *)jsonStringEncoded {
    if ([NSJSONSerialization isValidJSONObject:self]) {
        NSError *error;
        NSData *jsonData = [NSJSONSerialization dataWithJSONObject:self options:0 error:&error];
        NSString *json = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
        return json;
    }
    return nil;
}

- (NSString *)jsonPrettyStringEncoded {
    if ([NSJSONSerialization isValidJSONObject:self]) {
        NSError *error;
        NSData *jsonData = [NSJSONSerialization dataWithJSONObject:self options:NSJSONWritingPrettyPrinted error:&error];
        NSString *json = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
        return json;
    }
    return nil;
}

- (NSArray *)allKeysSorted {
    return [[self allKeys] sortedArrayUsingSelector:@selector(caseInsensitiveCompare:)];
}

- (NSArray *)allValuesSortedByKeys {
    NSArray *sortedKeys = [self allKeysSorted];
    NSMutableArray *arr = [[NSMutableArray alloc] init];
    for (id key in sortedKeys) {
        [arr addObject:self[key]];
    }
    return arr;
}

@end

@implementation NSMutableDictionary(PJCategory)

- (void)safeSetObject:(id)object forKey:(NSString *)key {
    if ( object && [key length] > 0 ) {
        [self setObject:object forKey:key];
    }
}

@end
