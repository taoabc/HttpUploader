// Uploader.cpp : Implementation of CUploader

#include "stdafx.h"
#include "Uploader.h"

#include <boost/thread/thread.hpp>
// CUploader

void TestThread(int a) {
}

void Test(void) {
  auto f1 = boost::bind(TestThread, 3);
  auto f = std::bind(TestThread, 1);
  boost::thread a(f);
  boost::thread b(f1);
}