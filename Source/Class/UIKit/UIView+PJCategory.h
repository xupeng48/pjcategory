//
//  UIView+PJCategory.h
//  PJCategory
//
//  Created by peng xu on 2019/3/21.
//  Copyright © 2019 xupeng. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView(PJAnimation)

/**
 模拟系统的spring动画
 */
+ (void)animateStandardWithAnimations:(void(^)(void))animations completion:(void(^)(BOOL finished))completion;

@end

@interface UIView (PJCategory)

/**
 设置部分圆角
 */
- (void)setRectCorner:(UIRectCorner)rectCorner cornerRadii:(CGSize)cornerRadii;

/**
 添加到superView中

 */
- (instancetype)addedTo:(UIView *)superView;

/**
 对当前View截图
 */
- (nullable UIImage *)snapshotImage;

/**
 比snapshotImage更快一些，但是可能导致屏幕俄更新
 See -[UIView drawViewHierarchyInRect:afterScreenUpdates:]
 */
- (nullable UIImage *)snapshotImageAfterScreenUpdates:(BOOL)afterUpdates;

/**
 根据View创建一个PDF
 */
- (nullable NSData *)snapshotPDF;

/**
 快捷设置layer的阴影
 */
- (void)setLayerShadow:(nullable UIColor*)color offset:(CGSize)offset radius:(CGFloat)radius;

/**
 删除所有的subView
 */
- (void)removeAllSubviews;

/**
 返回当前view的ViewController，可能为nil
 */
@property (nullable, nonatomic, readonly) UIViewController *viewController;

/**
 用户可见的alpha，包括了superView等混合
 */
@property (nonatomic, readonly) CGFloat visibleAlpha;

/**
 把当前坐标系的某一个点转换到指定view的坐标系
 */
- (CGPoint)convertPoint:(CGPoint)point toViewOrWindow:(nullable UIView *)view;

/**
 把指定view坐标系中的点转换到当前坐标系
 */
- (CGPoint)convertPoint:(CGPoint)point fromViewOrWindow:(nullable UIView *)view;

/**
 把当前坐标系的rect转换到指定view的坐标系
 */
- (CGRect)convertRect:(CGRect)rect toViewOrWindow:(nullable UIView *)view;

/**
 把指定view坐标系中的rect转换到当前坐标系
 */
- (CGRect)convertRect:(CGRect)rect fromViewOrWindow:(nullable UIView *)view;

/**
 frame.origin.x
 */
@property (nonatomic) CGFloat x;

/**
 frame.origin.y
 */
@property (nonatomic) CGFloat y;

/**
 frame.origin.x + frame.size.width
 */
@property (nonatomic, readonly) CGFloat maxX;

/**
 frame.origin.y + frame.size.height
 */
@property (nonatomic, readonly) CGFloat maxY;

/**
 frame.origin.x
 */
@property (nonatomic) CGFloat left;        ///< Shortcut for .

/**
 frame.origin.y
 */
@property (nonatomic) CGFloat top;

/**
  frame.origin.x + frame.size.width
 */
@property (nonatomic) CGFloat right;

/**
 frame.origin.y + frame.size.height
 */
@property (nonatomic) CGFloat bottom;

/**
 frame.size.width
 */
@property (nonatomic) CGFloat width;

/**
 frame.size.height.
 */
@property (nonatomic) CGFloat height;

/**
 center.x
 */
@property (nonatomic) CGFloat centerX;

/**
 center.y
 */
@property (nonatomic) CGFloat centerY;

/**
  frame.origin
 */
@property (nonatomic) CGPoint origin;

/**
 frame.size
 */
@property (nonatomic) CGSize  size; 

/**
 loop over all subviews
 */
@property (nonatomic, readonly) NSArray <UIView *> *pj_recurrenceAllSubviews;

@end

/**
 为XIB添加的快捷配置layer的属性
 */
@interface UIView (PJIBInspect)

@property (nonatomic, strong) IBInspectable UIColor *borderColor;
@property (nonatomic, assign) IBInspectable CGFloat borderWidth;
@property (nonatomic, assign) IBInspectable CGFloat cornerRadius;
@property (nonatomic, assign) IBInspectable BOOL maskToBounds;

@end

NS_ASSUME_NONNULL_END
