#include <iomanip>
#include <iostream>
#include <unicode/datefmt.h>
#include <unicode/errorcode.h>
#include <unicode/locid.h>
#include <unicode/smpdtfmt.h>
#include <unicode/unistr.h>

int main () {

    UErrorCode status;
    UnicodeString pattern ("d/m/Y");
    status = U_ZERO_ERROR;
    UnicodeString source ("");
    /*
    SimpleDateFormat* df = new SimpleDateFormat (pattern, status);
    UDate date = df->parse (source, status);
    Locale locale;
    UnicodeString result = df->getBestPattern (locale, source, status);
    std::cout << u_errorName (status) << std::endl;
    std::string res;
    result.toUTF8String (res);
    std::cout << result.length () << std::endl;
    */
    DateFormat* sd = DateFormat::createDateInstance ();
    sd->setLenient (false);
    sd->parse (source, status);

    if (U_SUCCESS (status)) {
        std::cout << "YES";
    }
    std::cout << u_errorName (status);

    return 0;
}