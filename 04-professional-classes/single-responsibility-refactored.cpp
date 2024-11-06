#include <iostream>
#include <string>
/*
In this example:

- Report is only responsible for handling and generating the report content.
- ReportFormatter takes care of formatting the report.
- ReportPrinter manages the output of the report.
*/
class Report {
private:
    std::string content;

public:
    Report(const std::string& text) : content(text) {}

    void generate() {
        content = "Report Content: " + content;
    }

    std::string getContent() const {
        return content;
    }
};

class ReportFormatter {
public:
    std::string format(const Report& report) {
        return "Formatted Report: " + report.getContent();
    }
};

class ReportPrinter {
public:
    void print(const std::string& formattedReport) {
        std::cout << formattedReport << std::endl;
    }
};

int main() {
    Report report("Annual Financial Summary");
    report.generate();

    ReportFormatter formatter;
    std::string formattedReport = formatter.format(report);

    ReportPrinter printer;
    printer.print(formattedReport);

    return 0;
}
