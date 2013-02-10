//
//  PSPDFSearchResultCell.h
//  PSPDFKit
//
//  Copyright (c) 2013 Peter Steinberger. All rights reserved.
//

#import "PSPDFKit.h"

///
/// Cell that is used to display a search result
///
@interface PSPDFSearchResultCell : UITableViewCell

@property (nonatomic, strong) PSPDFAttributedLabel *searchPreviewLabel;

/// Set the page rect so that the image coords can be calculated even before the image is rendered/loaded from the cache.
@property (nonatomic, assign) CGRect rotatedPageRect;

/// Page preview image.
@property (nonatomic, strong) UIImage *pagePreviewImage;

@end
