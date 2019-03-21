//
//  UIFont+PJCategory.h
//  PJCategory
//
//  Created by peng xu on 2019/3/21.
//  Copyright © 2019 xupeng. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreText/CoreText.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIFont (PJCategory)

#pragma mark - Font Traits

/// 是否加粗
@property (nonatomic, readonly) BOOL isBold NS_AVAILABLE_IOS(7_0);

///是否斜体
@property (nonatomic, readonly) BOOL isItalic NS_AVAILABLE_IOS(7_0);

/// 等宽字体
@property (nonatomic, readonly) BOOL isMonoSpace NS_AVAILABLE_IOS(7_0);

//彩色字形，比如表情
@property (nonatomic, readonly) BOOL isColorGlyphs NS_AVAILABLE_IOS(7_0);

/**
 字体粗细 -1.0 ～ 1.0
 */
@property (nonatomic, readonly) CGFloat fontWeight NS_AVAILABLE_IOS(7_0);

/**
 加粗当前字体
 */
- (nullable UIFont *)fontWithBold NS_AVAILABLE_IOS(7_0);

/**
 倾斜当前字体
 */
- (nullable UIFont *)fontWithItalic NS_AVAILABLE_IOS(7_0);

/**
 加粗和倾斜当前字体
 */
- (nullable UIFont *)fontWithBoldItalic NS_AVAILABLE_IOS(7_0);

/**
 返回一个普通字体(没有加粗，倾斜...)
 */
- (nullable UIFont *)fontWithNormal NS_AVAILABLE_IOS(7_0);

#pragma mark - Create font

/**
 由CTFontRef创建一个UIFont
 */
+ (nullable UIFont *)fontWithCTFont:(CTFontRef)CTFont;

/**
  由CTFontRef和Size创建一个UIFont
 */
+ (nullable UIFont *)fontWithCGFont:(CGFontRef)CGFont size:(CGFloat)size;

/**
  由当前字体生成一个CTFontRef，注意需要调用CFRelease()
 */
- (nullable CTFontRef)CTFontRef CF_RETURNS_RETAINED;

/**
 由当前字体生成一个CGFontRef，注意需要调用CFRelease()
 */
- (nullable CGFontRef)CGFontRef CF_RETURNS_RETAINED;


#pragma mark - Load and unload font
/**
 装载字体，支持(TTF,OTF).

 装载成功后，可以通过[UIFont fontWithName:...]创建字体
 */
+ (BOOL)loadFontFromPath:(NSString *)path;

/**
 卸载制定path的字体
 */
+ (void)unloadFontFromPath:(NSString *)path;

/**
 装载字体，支持(TTF,OTF).
 */
+ (nullable UIFont *)loadFontFromData:(NSData *)data;

/**
 卸载由loadFontFromData装载的字体
 */
+ (BOOL)unloadFontFromData:(UIFont *)font;


#pragma mark - Dump font data

/**
 序列化字体
 */
+ (nullable NSData *)dataFromFont:(UIFont *)font;

/**
 序列化字体
 */
+ (nullable NSData *)dataFromCGFont:(CGFontRef)cgFont;

@end

NS_ASSUME_NONNULL_END
