//
//  UIScrollView+PJCategory.h
//  PJCategory
//
//  Created by peng xu on 2019/3/21.
//  Copyright © 2019 xupeng. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIScrollView (PJCategory)

/**
 滚动到顶部
 */
- (void)scrollToTop;

/**
 滚动到底部
 */
- (void)scrollToBottom;

/**
 滚动到左侧
 */
- (void)scrollToLeft;

/**
 滚动到右侧
 */
- (void)scrollToRight;

/**
 滚动到顶部
 
 @param animated 是否要动画
 */
- (void)scrollToTopAnimated:(BOOL)animated;

/**
 滚动到底部
 
 @param animated  是否要动画
 */
- (void)scrollToBottomAnimated:(BOOL)animated;

/**
 滚动到左侧
 
 @param animated  是否要动画
 */
- (void)scrollToLeftAnimated:(BOOL)animated;

/**
 滚动到右侧
 
 @param animated  是否要动画
 */
- (void)scrollToRightAnimated:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END
