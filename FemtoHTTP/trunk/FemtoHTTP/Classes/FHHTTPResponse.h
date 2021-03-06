//
//  FHHTTPResponse.h
//  FemtoHTTP
//
//  Created by Ben Vanik on 10/12/08.
//  Copyright 2008 Ben Vanik ( http://www.noxa.org ). All rights reserved.
//

#import <Foundation/Foundation.h>

/*! \file
 * \brief Structures related to HTTP responses.
 */

/*!
 * An HTTP response as returned from the successful issuing of a command.
 */
@interface FHHTTPResponse : NSObject {
    NSURL*          url;
    NSURL*          redirectedFrom;
    NSDictionary*   headers;
    FHErrorCode     statusCode;
    NSString*       statusReason;
    NSArray*        cookies;
    
    NSString*       location;
    NSDate*         lastModified;
    NSString*       contentType;

    NSString*       contentEncoding;
    NSData*         content;
}

/*!
 * The URL of the content. If a redirect occured, this may differ from the request URL - check \c redirectedFrom to detect a redirect.
 */
@property (nonatomic, readonly) NSURL* url;
/*!
 * The original URL before redirection or \c nil if no redirect occured.
 */
@property (nonatomic, readonly) NSURL* redirectedFrom;
/*!
 * All header/value pairs returned by the server. All header keys are in lower-case and values are in the format they were received in.
 */
@property (nonatomic, readonly) NSDictionary* headers;
/*!
 * The HTTP status code returned by the server.
 */
@property (nonatomic, readonly) FHErrorCode statusCode;
/*!
 * The HTTP status reason returned by the server.
 */
@property (nonatomic, readonly) NSString* statusReason;
/*!
 * All the cookies returned by the server.
 */
@property (nonatomic, readonly) NSArray* cookies;

/*!
 * The redirect URI used in 3xx redirects.
 */
@property (nonatomic, readonly) NSString* location;
/*!
 * The date the requested content was last modified (if applicable).
 */
@property (nonatomic, readonly) NSDate* lastModified;
/*!
 * The full content type of the response. Use \c mimeType if you want only the MIME type of the response.
 * \warning May contain extra data tagged on the end, ex. <tt>text/html; charset=ISO-8859-4</tt>.
 */
@property (nonatomic, readonly) NSString* contentType;
/*!
 * The MIME type of the response or \c nil if unknown.
 */
@property (nonatomic, readonly) NSString* mimeType;

/*!
 * The content encoding of the data received from the server.
 */
@property (nonatomic, readonly) NSString* contentEncoding;
/*!
 * The data received from the server.
 */
@property (nonatomic, readonly) NSData* content;
/*!
 * The data received from the server in string form.
 * \warning The result of this property requires conversion and may be slow.
 */
@property (nonatomic, readonly) NSString* contentAsString;

/*!
 * Returns \c YES if the contents of this response are compressed.
 */
- (BOOL) isCompressed;

/*!
 * Decompress the contents of the response.
 * @return \c YES if decompression completed successfully.
 */
- (BOOL) decompress;

/*!
 * Get the value for the given header key.
 * @param key The key of the header to look up.
 * @return The value of the header with the given key or \c nil if not present.
 */
- (NSString*) valueForHeader:(NSString*)key;

@end
