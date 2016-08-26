
(function($, window, document, undefined) {
    'use strict';

    var header_helpers = function(class_array) {
        var i = class_array.length;
        var head = $('head');

        while (i--) {
            if (head.has('.' + class_array[i]).length === 0) {
                head.append('<meta class="' + class_array[i] + '" />');
            }
        }
    };

    header_helpers([
        'foundation-mq-small',
        'foundation-mq-small-only',
        'foundation-mq-medium',
        'foundation-mq-medium-only',
        'foundation-mq-large',
        'foundation-mq-large-only',
        'foundation-mq-xlarge',
        'foundation-mq-xlarge-only',
        'foundation-mq-xxlarge',
        'foundation-data-attribute-namespace'
    ]);

    var S = function(selector, context) {
        if (typeof selector === 'string') {
            if (context) {
                var cont;
                if (context.jquery) {
                    cont = context[0];
                    if (!cont) {
                        return context;
                    }
                } else {
                    cont = context;
                }
                return $(cont.querySelectorAll(selector));
            }

            return $(document.querySelectorAll(selector));
        }

        return $(selector, context);
    };

    window.matchMedia = window.matchMedia || (function(doc) {

        'use strict';

        var bool,
            docElem = doc.documentElement,
            refNode = docElem.firstElementChild || docElem.firstChild,
            // fakeBody required for <FF4 when executed in <head>
            fakeBody = doc.createElement('body'),
            div = doc.createElement('div');

        div.id = 'mq-test-1';
        div.style.cssText = 'position:absolute;top:-100em';
        fakeBody.style.background = 'none';
        fakeBody.appendChild(div);

        return function(q) {

            div.innerHTML = '&shy;<style media="' + q + '"> #mq-test-1 { width: 42px; }</style>';

            docElem.insertBefore(fakeBody, refNode);
            bool = div.offsetWidth === 42;
            docElem.removeChild(fakeBody);

            return {
                matches: bool,
                media: q
            };

        };

    }(document));

    window.Foundation = {
        name: 'Foundation',

        version: '5.5.1',

        media_queries: {
            'small': S('.foundation-mq-small').css('font-family').replace(/^[\/\\'"]+|(;\s?})+|[\/\\'"]+$/g, ''),
            'small-only': S('.foundation-mq-small-only').css('font-family').replace(/^[\/\\'"]+|(;\s?})+|[\/\\'"]+$/g, ''),
            'medium': S('.foundation-mq-medium').css('font-family').replace(/^[\/\\'"]+|(;\s?})+|[\/\\'"]+$/g, ''),
            'medium-only': S('.foundation-mq-medium-only').css('font-family').replace(/^[\/\\'"]+|(;\s?})+|[\/\\'"]+$/g, ''),
            'large': S('.foundation-mq-large').css('font-family').replace(/^[\/\\'"]+|(;\s?})+|[\/\\'"]+$/g, ''),
            'large-only': S('.foundation-mq-large-only').css('font-family').replace(/^[\/\\'"]+|(;\s?})+|[\/\\'"]+$/g, ''),
            'xlarge': S('.foundation-mq-xlarge').css('font-family').replace(/^[\/\\'"]+|(;\s?})+|[\/\\'"]+$/g, ''),
            'xlarge-only': S('.foundation-mq-xlarge-only').css('font-family').replace(/^[\/\\'"]+|(;\s?})+|[\/\\'"]+$/g, ''),
            'xxlarge': S('.foundation-mq-xxlarge').css('font-family').replace(/^[\/\\'"]+|(;\s?})+|[\/\\'"]+$/g, '')
        },

        utils: {

            S: S,

            match: function(mq) {
                return window.matchMedia(mq).matches;
            },

            is_small_up: function() {
                return this.match(Foundation.media_queries.small);
            },

            is_medium_up: function() {
                return this.match(Foundation.media_queries.medium);
            },

            is_large_up: function() {
                return this.match(Foundation.media_queries.large);
            },

            is_xlarge_up: function() {
                return this.match(Foundation.media_queries.xlarge);
            },

            is_xxlarge_up: function() {
                return this.match(Foundation.media_queries.xxlarge);
            },

            is_small_only: function() {
                return !this.is_medium_up() && !this.is_large_up() && !this.is_xlarge_up() && !this.is_xxlarge_up();
            },

            is_medium_only: function() {
                return this.is_medium_up() && !this.is_large_up() && !this.is_xlarge_up() && !this.is_xxlarge_up();
            },

            is_large_only: function() {
                return this.is_medium_up() && this.is_large_up() && !this.is_xlarge_up() && !this.is_xxlarge_up();
            },

            is_xlarge_only: function() {
                return this.is_medium_up() && this.is_large_up() && this.is_xlarge_up() && !this.is_xxlarge_up();
            },

            is_xxlarge_only: function() {
                return this.is_medium_up() && this.is_large_up() && this.is_xlarge_up() && this.is_xxlarge_up();
            }
        }
    };

}(jQuery, window, window.document));;

$(document).ready (function(){
	
	if (Foundation.utils.is_large_up()) {
		carousel_wrap.className='';
		carousel.className='owl-carousel';
	} else {
		carousel_wrap.className='carousel_off';
		carousel.className='';
	}
	
}); 	

