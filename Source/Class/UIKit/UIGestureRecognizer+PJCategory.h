//
//  UIGestureRecognizer+PJCategory.h
//  PJCategory
//
//  Created by peng xu on 2019/3/21.
//  Copyright © 2019 xupeng. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIGestureRecognizer (PJCategory)

/**
 由block创建手势
 */
- (instancetype)initWithActionBlock:(void (^)(id sender))block;

/**
 添加target/action的block
 */
- (void)addActionBlock:(void (^)(id sender))block;

/**
 删除全部block
 */
- (void)removeAllActionBlocks;

@end

NS_ASSUME_NONNULL_END
