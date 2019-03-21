//
//  NSData+PJCategory.h
//  PJCategory
//
//  Created by peng xu on 2019/3/21.
//  Copyright © 2019 xupeng. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSData (PJCategory)

#pragma mark - Hash

/**
 md2哈希，小写字符串
 */
- (NSString *)md2String;

/**
 md2哈希
 */
- (NSData *)md2Data;

/**
 md4哈希，小写字符串
 */
- (NSString *)md4String;

/**
 md4哈希
 */
- (NSData *)md4Data;

/**
 md5哈希，小写字符串
 */
- (NSString *)md5String;

/**
 md5哈希
 */
- (NSData *)md5Data;

/**
 sha1哈希，小写字符串
 */
- (NSString *)sha1String;

/**
 sha1哈希
 */
- (NSData *)sha1Data;

/**
 sha224哈希，小写字符串
 */
- (NSString *)sha224String;

/**
 sha224哈希
 */
- (NSData *)sha224Data;

/**
 sha256哈希，小写字符串
 */
- (NSString *)sha256String;

/**
 sha256哈希
 */
- (NSData *)sha256Data;

/**
 sha384哈希，小写字符串
 */
- (NSString *)sha384String;

/**
 sha384哈希
 */
- (NSData *)sha384Data;

/**
 sha512哈希，小写字符串
 */
- (NSString *)sha512String;

/**
 sha512哈希
 */
- (NSData *)sha512Data;

/**
 hmacMD5 小写字符串
 */
- (NSString *)hmacMD5StringWithKey:(NSString *)key;

/**
 hmacMD5
 */
- (NSData *)hmacMD5DataWithKey:(NSData *)key;

/**
 hmacSHA1 小写字符串
 */
- (NSString *)hmacSHA1StringWithKey:(NSString *)key;

/**
 hmacSHA1
 */
- (NSData *)hmacSHA1DataWithKey:(NSData *)key;

/**
 hmacSHA224 小写字符串
 */
- (NSString *)hmacSHA224StringWithKey:(NSString *)key;

/**
 hmacSHA224
 */
- (NSData *)hmacSHA224DataWithKey:(NSData *)key;

/**
 hmacSHA256，小写字符串
 */
- (NSString *)hmacSHA256StringWithKey:(NSString *)key;

/**
 hmacSHA256
 */
- (NSData *)hmacSHA256DataWithKey:(NSData *)key;

/**
 hmacSHA384，小写字符串
 */
- (NSString *)hmacSHA384StringWithKey:(NSString *)key;

/**
 hmacSHA384
 */
- (NSData *)hmacSHA384DataWithKey:(NSData *)key;

/**
 hmacSHA512，小写字符串
 */
- (NSString *)hmacSHA512StringWithKey:(NSString *)key;

/**
 hmacSHA512
 */
- (NSData *)hmacSHA512DataWithKey:(NSData *)key;

/**
 crc32 hash，小写字符串
 */
- (NSString *)crc32String;

/**
 crc32哈希
 */
- (uint32_t)crc32;


#pragma mark - Encrypt and Decrypt
/**
 aes256加密
 
 @param key   16, 24，32，128, 192 ，256bits的密钥
 @param iv    16(128bits) initialization vector,可以是nil
 @return      An NSData decrypted, or nil if an error occurs.
 */
- (nullable NSData *)aes256EncryptWithKey:(NSData *)key iv:(nullable NSData *)iv;

/**
 aes256解密
 
 @param key   16, 24，32，128, 192 ，256bits的密钥
 @param iv    16(128bits) initialization vector,可以是nil
 @return      An NSData decrypted, or nil if an error occurs.
 */

- (nullable NSData *)aes256DecryptWithkey:(NSData *)key iv:(nullable NSData *)iv;


/**
 根据public key进行解密
 */
- (NSData *)rsa_decryptDataWithPublicKey:(NSString *)publicKey;


/**
 根据publick key 进行加密
 
 @param key 公钥
 @return 加密后的数据
 */
-(NSData *)rsa_encryptDataWithPublicKey:(NSString *)key;


/**
 RC4加密
 */
- (NSData *)encryptUseRC4WithKey:(NSString *)key;

#pragma mark - Encode and decode
/**
 用UTF8解码
 */
- (nullable NSString *)utf8String;

/**
 转换成大写的NSString
 */
- (nullable NSString *)hexString;

/**
 16进制字符串创建data
 */
+ (nullable NSData *)dataWithHexString:(NSString *)hexString;

/**
 base64编码过的字符串
 */
- (nullable NSString *)base64EncodedString;

/**
 由base64编码过的字符串创建
 */
+ (nullable NSData *)dataWithBase64EncodedString:(NSString *)base64EncodedString;

/**
 解码数据，可能为nil
 */
- (nullable id)jsonValueDecoded;


#pragma mark - Inflate and deflate
/**
 gzip解压缩
 */
- (nullable NSData *)gzipInflate;

/**
 gzip压缩，压缩等级默认
 */
- (nullable NSData *)gzipDeflate;

/**
 zlib解压缩
 */
- (nullable NSData *)zlibInflate;

/**
 zlib压缩
 */
- (nullable NSData *)zlibDeflate;


#pragma mark - Others

/**
 由MainBundle文件创建data，类似[UIImage imageNamed:].
 */
+ (nullable NSData *)dataNamed:(NSString *)name;



@end

NS_ASSUME_NONNULL_END
