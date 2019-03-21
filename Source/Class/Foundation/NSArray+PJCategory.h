//
//  NSArray+PJCategory.h
//  PJCategory
//
//  Created by peng xu on 2019/3/21.
//  Copyright © 2019 xupeng. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSArray (PJCategory)

/**
 是否包含一个字符串
 */
- (BOOL)containsString:(NSString *)destString;

/**
 找不到会返回-1，有待改进
 */
- (int)indexOfString:(NSString *)destString;

#pragma mark - Encode

/**
 转换成JSON的字符串，非PrettyPrinted
 */
- (nullable NSString *)jsonStringEncoded;

/**
 转换成JSON的字符串，PrettyPrinted
 */
- (nullable NSString *)jsonPrettyStringEncoded;

@end



// MARK: -- 函数式扩展
@interface NSArray<ObjectType> (xOperations)

/**
 安全取值
 */
@property (nonatomic, readonly) ObjectType (^pj_safeObjIdx)(NSUInteger index);

/**
 过滤

 @param predicate 条件block
 @return 满足条件的数组
 */
- (NSArray<__kindof ObjectType> *)filter:(BOOL(^)(ObjectType item))predicate;

/**
 映射

 @param selector 处理的block
 @return 映射后的结果
 */
- (NSArray *)map:(id(^)(ObjectType item))selector;

/**
 映射，包含index

 @param selector 处理的block
 @return 映射后的结果
 */
- (NSArray *)mapWithIndex:(id(^)(ObjectType item,NSInteger idx))selector;

/**
 找到第一个满足条件的结果

 @param predicate 条件
 @return 第一个满足条件的结果，可能为nil
 */
- (nullable ObjectType)first:(BOOL(^)(ObjectType item))predicate;

/**
 前n个数据，如果当前个数小于n个，那么会返回当前个数
 */
- (NSMutableArray<ObjectType> *)preffixArrayOfCount:(NSInteger)count;

/**
 后n个数据，如果当前个数小于n个，那么会返回当前个数
 */
- (NSMutableArray<ObjectType> *)suffixArrayOfCount:(NSInteger)count;

/**
 反转
 */
- (NSArray<ObjectType> *)reverse;

/**
 是否全部满足条件
 */
- (BOOL)all:(BOOL(^)(ObjectType item))predicate;

/**
 是否包含满足条件的数据
 */
- (BOOL)any:(BOOL(^)(ObjectType item))predicate;

/**
 遍历
 */
- (void)each:(void(^)(ObjectType item))action;

/**
 遍历
 */
- (void)eachWithIndex:(void(^)(ObjectType item,NSInteger idx))action;

/**
 找到第一个满足的index
 */
- (NSInteger)indexOf:(BOOL(^)(ObjectType item))predicate;

@end



// MARK: -- NSMutableArray
@interface NSMutableArray (PJCategory)

/**
 删除第一个数据，如果数组为空，不会有任何作用
 */
- (void)removeFirstObject;

/**
 删除最后一个数据，如果数组为空，不会有任何作用
 */
- (void)removeLastObject;

/**
 删除并返回第一个数据，如果数组为空，不会有任何作用
 */
- (nullable id)popFirstObject;

/**
 删除并返回最后一个数据，如果数组为空，不会有任何作用
 */
- (nullable id)popLastObject;

/**
 在末尾添加数据
 */
- (void)appendObject:(id)anObject;

/**
 在头部插入数据
 */
- (void)prependObject:(id)anObject;

/**
 把一组数据添加到当前的末尾
 */
- (void)appendObjects:(NSArray *)objects;

/**
 一组数据插入到当前的头部
 */
- (void)prependObjects:(NSArray *)objects;

/**
 指定位置插入一组数据
 */
- (void)insertObjects:(NSArray *)objects atIndex:(NSUInteger)index;

/**
 随机交换当前数组中的内容
 */
- (void)shuffle;

@end
