//
//  NSArray+PJCategory.m
//  PJCategory
//
//  Created by peng xu on 2019/3/21.
//  Copyright © 2019 xupeng. All rights reserved.
//

#import "NSArray+PJCategory.h"

@implementation NSArray (PJCategory)

- (BOOL)containsString:(NSString *)destString {
    NSArray *copyed = [self copy];
    for (NSString *_str in copyed) {
        if (![_str isKindOfClass:[NSString class]]) {
            continue;
        }
        if ( [_str isEqualToString:destString] ) {
            return YES;
        }
    }
    return NO;
}

- (int)indexOfString:(NSString *)destString {
    for ( int i = 0 ; i < self.count ; i++ ) {
        id obj = [self objectAtIndex:i];
        if (![obj isKindOfClass:[NSString class]]) {
            continue;
        }
        if ([obj isEqualToString:destString] ) {
            return i;
        }
    }
    return -1;
}

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

@end


// MARK: -- 函数式扩展
@implementation NSArray (xOperations)

- (id (^)(NSUInteger))pj_safeObjIdx {
    __weak typeof(self) weakSelf = self;
    id (^block)(NSUInteger index) = ^(NSUInteger index) {
        return (weakSelf.count-1)<index ? nil : weakSelf[index];
    };
    return block;
}

- (NSArray *)filter:(BOOL (^)(id))predicate {
    if (!predicate) return self;
    NSMutableArray *result = [NSMutableArray array];
    for (id item in self) {
        if (predicate(item)) {
            [result addObject:item];
        }
    }
    return result;
}

- (NSArray *)map:(id (^)(id))selector {
    if (!selector) return self;
    // Capacity:avoid size change.
    NSMutableArray *result =[NSMutableArray arrayWithCapacity:self.count];
    for (id item in self) {
        id mapResult = selector(item);
        if (mapResult) [result addObject:mapResult];
    }
    return result;
}

- (NSArray *)mapWithIndex:(id (^)(id, NSInteger))selector {
    if (!selector) return self;
    // Capacity:avoid size change.
    NSMutableArray *result =[NSMutableArray arrayWithCapacity:self.count];
    for (int i = 0; i < self.count; i++) {
        id mapResult = selector([self objectAtIndex:i],i);
        if (mapResult) [result addObject:mapResult];
    }
    return result;
}

- (NSMutableArray *)preffixArrayOfCount:(NSInteger)count{
    if(count < 0){
        return nil;
    }
    NSMutableArray *result =[NSMutableArray arrayWithCapacity:count];
    for (int i = 0; i < count && i < self.count; i++) {
        [result addObject:[self objectAtIndex:i]];
    }
    return result;
}

- (NSMutableArray *)suffixArrayOfCount:(NSInteger)count{
    if(count < 0){
        return nil;
    }
    NSMutableArray *result =[NSMutableArray arrayWithCapacity:count];
    long i = self.count - count;
    i = i < 0 ? 0 : i;
    for (; i < self.count; i++) {
        [result addObject:[self objectAtIndex:i]];
    }
    return result;
}

- (id)first:(BOOL (^)(id))predicate {
    if (!predicate) return self.firstObject;
    for (id item in self) {
        if (predicate(item)) {
            return item;
        }
    }
    return nil;
}

- (NSArray *)reverse {
    return [self reverseObjectEnumerator].allObjects;
}

- (BOOL)all:(BOOL (^)(id))predicate {
    if (!predicate) return NO;
    for (id item in self) {
        if (!predicate(item)) {
            return NO;
        }
    }
    return YES;
}

- (BOOL)any:(BOOL (^)(id))predicate {
    if (!predicate) return NO;
    for (id item in self) {
        if(predicate(item)) {
            return YES;
        }
    }
    return NO;
}

- (void)each:(void (^)(id))action {
    if (!action) return;
    for (id item in self) {
        action(item);
    }
}

- (void)eachWithIndex:(void (^)(id, NSInteger))action {
    if (!action) return;
    for (int i = 0; i < self.count; i++) {
        id item = [self objectAtIndex:i];
        action(item,i);
    }
}

- (NSInteger)indexOf:(BOOL (^)(id))predicate {
    if (!predicate) return NSNotFound;
    for (NSInteger i = 0; i < self.count; i++) {
        id item = self[i];
        if (predicate(item)) return i;
    }
    return NSNotFound;
}

@end


// MARK: -- NSMutableArray

@implementation NSMutableArray (PJCategory)

- (void)removeFirstObject {
    if (self.count) {
        [self removeObjectAtIndex:0];
    }
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-protocol-method-implementation"
- (void)removeLastObject {
    if (self.count) {
        [self removeObjectAtIndex:self.count - 1];
    }
}

#pragma clang diagnostic pop

- (id)popFirstObject {
    id obj = nil;
    if (self.count) {
        obj = self.firstObject;
        [self removeFirstObject];
    }
    return obj;
}

- (id)popLastObject {
    id obj = nil;
    if (self.count) {
        obj = self.lastObject;
        [self removeLastObject];
    }
    return obj;
}

- (void)appendObject:(id)anObject {
    [self addObject:anObject];
}

- (void)prependObject:(id)anObject {
    [self insertObject:anObject atIndex:0];
}

- (void)appendObjects:(NSArray *)objects {
    if (!objects) return;
    [self addObjectsFromArray:objects];
}

- (void)prependObjects:(NSArray *)objects {
    if (!objects) return;
    NSUInteger i = 0;
    for (id obj in objects) {
        [self insertObject:obj atIndex:i++];
    }
}

- (void)insertObjects:(NSArray *)objects atIndex:(NSUInteger)index {
    NSUInteger i = index;
    for (id obj in objects) {
        [self insertObject:obj atIndex:i++];
    }
}

- (void)shuffle {
    for (NSUInteger i = self.count; i > 1; i--) {
        [self exchangeObjectAtIndex:(i - 1)
                  withObjectAtIndex:arc4random_uniform((u_int32_t)i)];
    }
}

@end
