class CountUpTimer {
public:
  CountUpTimer();
  void Start();
  void Stop();
  void Reset();
  int GetElapsedTime() const;
  bool IsRunning() const;
};