//
//  NSString+PJCategory.h
//  PJCategory
//
//  Created by peng xu on 2019/3/21.
//  Copyright © 2019 xupeng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (PJCategory)

#pragma mark - Hash

/**
 小写的md2哈希字符串
 */
- (nullable NSString *)md2String;

/**
 小写的md4哈希字符串
 */
- (nullable NSString *)md4String;

/**
 小写的md5哈希字符串
 */
- (nullable NSString *)md5String;

/**
 小写的sha1哈希字符串
 */
- (nullable NSString *)sha1String;

/**
 小写的sha224哈希字符串
 */
- (nullable NSString *)sha224String;

/**
 小写的sha256哈希字符串
 */
- (nullable NSString *)sha256String;

/**
 小写的sha384哈希字符串
 */
- (nullable NSString *)sha384String;

/**
 小写的sha512哈希字符串
 */
- (nullable NSString *)sha512String;

/**
 小写的hmacMD5字符串
 */
- (nullable NSString *)hmacMD5StringWithKey:(NSString *)key;

/**
 小写的hmacSHA1字符串
 */
- (nullable NSString *)hmacSHA1StringWithKey:(NSString *)key;

/**
 小写的hmacSHA224字符串
 */
- (nullable NSString *)hmacSHA224StringWithKey:(NSString *)key;

/**
 小写的hmacSHA256字符串
 */
- (nullable NSString *)hmacSHA256StringWithKey:(NSString *)key;

/**
 小写的hmacSHA384字符串
 */
- (nullable NSString *)hmacSHA384StringWithKey:(NSString *)key;

/**
 小写的hmacSHA512字符串
 */
- (nullable NSString *)hmacSHA512StringWithKey:(NSString *)key;

/**
 小写的crc32哈希字符串
 */
- (nullable NSString *)crc32String;


#pragma mark - Encode and decode

/**
 base64编码
 */
- (nullable NSString *)base64EncodedString;

/**
 由base64编码过的字符串创建一个字符串
 */
+ (nullable NSString *)stringWithBase64EncodedString:(NSString *)base64EncodedString;

/**
 URL encode
 */
- (NSString *)stringByURLEncode;

/**
 URL decode
 */
- (NSString *)stringByURLDecode;

/**
 Escape HTML
 eg: "a>b" => "a&gt;b".
 */
- (NSString *)stringByEscapingHTML;

#pragma mark - Drawing

/**
 计算字符串大小
 
 @param font          字体
 
 @param size          最大的可接受大小，这个大小决定了什么时候换行
 
 @param lineBreakMode 换行模式
 
 @return              包含字符串的长宽
 */
- (CGSize)sizeForFont:(UIFont *)font size:(CGSize)size mode:(NSLineBreakMode)lineBreakMode;

/**
 字符串以一行的方式渲染的宽度
 
 @param font  字体
 */
- (CGFloat)widthForFont:(UIFont *)font;

/**
 以字体和定宽来计算字符串的高度
 */
- (CGFloat)heightForFont:(UIFont *)font width:(CGFloat)width;


#pragma mark - Regular Expression

/**
    是否匹配正则表达式
 */
- (BOOL)matchesRegex:(NSString *)regex options:(NSRegularExpressionOptions)options;

/**
 正则匹配，并且对每一个匹配的结果执行block
 
 @param regex    正则
 @param options  正则匹配的规则
 @param block    执行的block
 Block的参数
 match: 匹配到的字符串
 matchRange: 匹配的区间
 stop: 设置为YES回停止
 */
- (void)enumerateRegexMatches:(NSString *)regex
                      options:(NSRegularExpressionOptions)options
                   usingBlock:(void (^)(NSString *match, NSRange matchRange, BOOL *stop))block;

/**
 正则替换
 
 @param regex       正则表达式
 @param options     正则匹配的参数
 @param replacement 替换成的字符串
 */
- (NSString *)stringByReplacingRegex:(NSString *)regex
                             options:(NSRegularExpressionOptions)options
                          withString:(NSString *)replacement;


#pragma mark - NSNumber Compatible

@property (readonly) char charValue;
@property (readonly) unsigned char unsignedCharValue;
@property (readonly) short shortValue;
@property (readonly) unsigned short unsignedShortValue;
@property (readonly) unsigned int unsignedIntValue;
@property (readonly) long longValue;
@property (readonly) unsigned long unsignedLongValue;
@property (readonly) unsigned long long unsignedLongLongValue;
@property (readonly) NSUInteger unsignedIntegerValue;


#pragma mark - Utilities

/**
 创建一个新的uuid
 */
+ (NSString *)stringWithUUID;

/**
 删除头尾的空白
 */
- (NSString *)stringByTrim;

/**
 增加sacle到路径当中，不包括extensition
 From @"name" to @"name@2x".
 
 e.g.
 <table>
 <tr><th>Before     </th><th>After(scale:2)</th></tr>
 <tr><td>"icon"     </td><td>"icon@2x"     </td></tr>
 <tr><td>"icon "    </td><td>"icon @2x"    </td></tr>
 <tr><td>"icon.top" </td><td>"icon.top@2x" </td></tr>
 <tr><td>"/p/name"  </td><td>"/p/name@2x"  </td></tr>
 <tr><td>"/path/"   </td><td>"/path/"      </td></tr>
 </table>
 */
- (NSString *)stringByAppendingNameScale:(CGFloat)scale;

/**
 增加sacle到路径当中，如果路径最后不是文件名，那么会返回nil
 @"name.png" => @"name@2x.png".
 
 e.g.
 <table>
 <tr><th>Before     </th><th>After(scale:2)</th></tr>
 <tr><td>"icon.png" </td><td>"icon@2x.png" </td></tr>
 <tr><td>"icon..png"</td><td>"icon.@2x.png"</td></tr>
 <tr><td>"icon"     </td><td>"icon@2x"     </td></tr>
 <tr><td>"icon "    </td><td>"icon @2x"    </td></tr>
 <tr><td>"icon."    </td><td>"icon.@2x"    </td></tr>
 <tr><td>"/p/name"  </td><td>"/p/name@2x"  </td></tr>
 <tr><td>"/path/"   </td><td>"/path/"      </td></tr>
 </table>
 */
- (NSString *)stringByAppendingPathScale:(CGFloat)scale;

/**
 返回路径当中的scale
 
 例如
 <table>
 <tr><th>Path            </th><th>Scale </th></tr>
 <tr><td>"icon.png"      </td><td>1     </td></tr>
 <tr><td>"icon@2x.png"   </td><td>2     </td></tr>
 <tr><td>"icon@2.5x.png" </td><td>2.5   </td></tr>
 <tr><td>"icon@2x"       </td><td>1     </td></tr>
 <tr><td>"icon@2x..png"  </td><td>1     </td></tr>
 <tr><td>"icon@2x.png/"  </td><td>1     </td></tr>
 </table>
 */
- (CGFloat)pathScale;

/**
 nil, @"", @"  ", @"\n"返回NO; 其余的YES
 */
- (BOOL)isNotBlank;


/**
 是否包含NSCharacterSet
 */
- (BOOL)containsCharacterSet:(NSCharacterSet *)set;

/**
 尝试把自己解析成NSNumber
 */
- (NSNumber *)numberValue;

/**
 UTF-8 encoding的字符串.
 */
- (NSData *)dataValue;

/**
 NSMakeRange(0, self.length).
 */
- (NSRange)rangeOfAll;

/**
 按照JSON字符串的格式解码，出错返回nil
 
 举例. NSString: @"{"name":"a","count":2}"  => NSDictionary: @[@"name":@"a",@"count":@2]
 */
- (id)jsonValueDecoded;

/**
 从MainBundle创建一个字符串，类似[UIImage imageNamed:].
 */
+ (NSString *)stringNamed:(NSString *)name;

@end

NS_ASSUME_NONNULL_END
