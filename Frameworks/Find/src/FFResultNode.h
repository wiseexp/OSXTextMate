#import "scan_path.h" // find::match_t
#import <document/document.h>

@interface FFResultNode : NSObject
@property (nonatomic, weak) FFResultNode* parent;
@property (nonatomic, readonly) NSUInteger countOfLeafs;
@property (nonatomic, readonly) NSUInteger countOfExcluded;
@property (nonatomic, readonly) NSUInteger countOfReadOnly;
@property (nonatomic, readonly) NSUInteger countOfExcludedReadOnly;

+ (FFResultNode*)resultNodeWithMatch:(find::match_t const&)aMatch baseDirectory:(NSString*)base;
+ (FFResultNode*)resultNodeWithMatch:(find::match_t const&)aMatch;

- (void)addResultNode:(FFResultNode*)aMatch;
- (void)removeFromParent;

- (FFResultNode*)firstResultNode;
- (FFResultNode*)lastResultNode;

- (NSUInteger)lineSpan;
- (NSAttributedString*)excerptWithReplacement:(NSString*)replacementString;
- (NSImage*)icon;

@property (nonatomic) NSString* replaceString;
@property (nonatomic) NSArray* children;
@property (nonatomic) BOOL excluded;
@property (nonatomic, getter = isReadOnly) BOOL readOnly;
@property (nonatomic) NSImage* icon;

@property (nonatomic, readonly) find::match_t const& match;
@property (nonatomic, readonly) document::document_ptr document;
@property (nonatomic, readonly) NSString* path;
@property (nonatomic, readonly) NSString* identifier;
@property (nonatomic) NSAttributedString* displayPath;
@end
