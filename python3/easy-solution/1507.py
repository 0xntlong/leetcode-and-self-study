"""
1507. Reformat Date
    Given a date string in the form Day Month Year, where:

    Day is in the set {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"}.
    Month is in the set {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}.
    Year is in the range [1900, 2100].
    Convert the date string to the format YYYY-MM-DD, where:

    YYYY denotes the 4 digit year.
    MM denotes the 2 digit month.
    DD denotes the 2 digit day.
    

    Example :
    Input: date = "20th Oct 2052"
    Output: "2052-10-20"
"""

class Solution:
    def reformatDate(self, date: str) -> str:
        s = date.split()
        MonthDict = {'Jan': '01', 'Feb': '02', 
                     'Mar': '03', 'Apr': '04', 
                     'May': '05', 'Jun': '06', 
                     'Jul': '07', 'Aug': '08', 
                     'Sep': '09', 'Oct': '10', 
                     'Nov': '11', 'Dec': '12'}
        day = s[0][:-2]
        month = s[1]
        year = s[2]
        if int(day) < 10:
            day = '0' + day
        return ''.join(f'{year}-{MonthDict[month]}-{day}')