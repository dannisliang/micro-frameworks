//
//  FDEnclosure.m
//  Feeds
//
//  Created by Ben Vanik on 10/7/08.
//  Copyright 2008 Ben Vanik ( http://www.noxa.org ). All rights reserved.
//

#import "FDEnclosure.h"
#import "FDEnclosure+Implementation.h"

@implementation FDEnclosure

@synthesize url;
@synthesize mimeType;
@synthesize length;

#pragma mark -
#pragma mark Initialization

- (id) initWithURL:(NSURL*)_url withMimeType:(NSString*)_mimeType andLength:(NSUInteger)_length
{
    if( self = [super init] )
    {
        BOOL argumentBad = NO;
        if( _url == nil )
        {
            argumentBad = YES;
#if defined( FD_EXCEPTIONS )
            [NSException raise:NSInvalidArgumentException format:@"URL must not be nil or empty"];
#endif
        }
        if( ( _mimeType == nil ) || ( [_mimeType length] == 0 ) )
        {
            argumentBad = YES;
#if defined( FD_EXCEPTIONS )
            [NSException raise:NSInvalidArgumentException format:@"Mime type must not be nil or empty"];
#endif
        }
        if( argumentBad == YES )
        {
            [self release];
            return nil;
        }
        
        url = [_url copy];
        mimeType = [_mimeType copy];
        length = _length;
    }
    return self;
}

- (void) dealloc
{
    [url release];
    url = nil;
    [mimeType release];
    mimeType = nil;
    [super dealloc];
}

#pragma mark -
#pragma mark Accessors

- (NSString*) description
{
    return [NSString stringWithFormat:@"%@ (%@)", [url absoluteString], mimeType];
}

@end
