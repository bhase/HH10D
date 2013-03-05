#ifndef D_HH10DBuildTime_H
#define D_HH10DBuildTime_H

///////////////////////////////////////////////////////////////////////////////
//
//  HH10DBuildTime is responsible for recording and reporting when
//  this project library was built
//
///////////////////////////////////////////////////////////////////////////////

class HH10DBuildTime
  {
  public:
    explicit HH10DBuildTime();
    virtual ~HH10DBuildTime();
    
    const char* GetDateTime();

  private:
      
    const char* dateTime;

    HH10DBuildTime(const HH10DBuildTime&);
    HH10DBuildTime& operator=(const HH10DBuildTime&);

  };

#endif  // D_HH10DBuildTime_H
