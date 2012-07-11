//
//  PSPDFRenderer.h
//  PSPDFKit
//
//  Copyright (c) 2012 Peter Steinberger. All rights reserved.
//

#import "PSPDFKitGlobal.h"

@class PSPDFDocument, PSPDFRenderJob, PSPDFRenderer;

// Implement this delegate to get rendered pages.
@protocol PSPDFRenderDelegate <NSObject>

- (void)renderer:(PSPDFRenderer *)renderer jobDidFinish:(PSPDFRenderJob *)job;

@end

/// Render Queue. Does not cache. Used for rendering pages/page parts in PSPDFPageView.
@interface PSPDFRenderer : NSObject

/// Cache is a singleton.
+ (PSPDFRenderer *)sharedPSPDFRenderer;

/// Requests a (freshly) rendered image from a specified document. Does not use the file cache.
- (void)requestRenderedImageForDocument:(PSPDFDocument *)document forPage:(NSUInteger)page withSize:(CGSize)size clippedToRect:(CGRect)clipRect withAnnotations:(NSArray *)annotations options:(NSDictionary *)options delegate:(id<PSPDFRenderDelegate>)delegate;

/// Cancels all queued render-calls.
- (void)cancelRenderingForDelegate:(id<PSPDFRenderDelegate>)delegate;

/// Returns YES if currently a RenderJob is scheduled or running for delegate.
- (BOOL)hasRenderJobsForDelegate:(id<PSPDFRenderDelegate>)delegate;

/// Returns the currently rendered renderJob.
- (PSPDFRenderJob *)currentRenderJob;

@end

@interface PSPDFRenderJob : NSObject

@property(nonatomic, readonly) NSUInteger page;
@property(nonatomic, readonly) PSPDFDocument *document;
@property(nonatomic, readonly) CGSize fullSize;
@property(nonatomic, readonly) CGRect clipRect;
@property(nonatomic, readonly) float zoomScale;
@property(nonatomic, readonly) NSArray *annotations;
@property(nonatomic, strong, readonly) NSDictionary *options;
@property(nonatomic, strong) id<PSPDFRenderDelegate> delegate;
@property(nonatomic, strong) UIImage *renderedImage;

- (id)initWithDocument:(PSPDFDocument *)document forPage:(NSUInteger)page withSize:(CGSize)size clippedToRect:(CGRect)clipRect withAnnotations:(NSArray *)annotations options:(NSDictionary *)options delegate:(id<PSPDFRenderDelegate>)delegate;

@end
