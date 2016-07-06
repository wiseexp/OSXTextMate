#import "PropertiesViewController.h"
#import <OakAppKit/OakKeyEquivalentView.h>

@implementation PropertiesViewController
- (id)initWithName:(NSString*)aName
{
	if((self = [super initWithNibName:aName bundle:[NSBundle bundleForClass:[self class]]]))
	{
		_properties = [NSMutableDictionary new];
	}
	return self;
}

- (CGFloat)indent
{
	return alignmentView ? NSMaxX([alignmentView frame]) + 5 : 20;
}

- (NSDictionary*)properties
{
	[objectController commitEditing];
	return _properties;
}

- (void)loadView
{
	[super loadView];
	[keyEquivalentView bind:NSValueBinding toObject:objectController withKeyPath:@"selection.keyEquivalent" options:nil];
}
@end
