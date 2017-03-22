#ifndef output_h
#define output_h

class outputClass
{
  public:
  outputClass();
  void SETUP();
  void playAudio();
  void queueFile(String fileName, bool stopPrevious);
};

extern outputClass Audio;

#endif
