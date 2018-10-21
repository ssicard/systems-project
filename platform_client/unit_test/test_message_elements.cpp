#include <iostream>

#include "../message_elements/RequestResource.h"

static float test_count = 0.0;
static float test_passed = 0.0;

void u_request_resource() {
  RequestResource test_msg_0;

  if(test_msg_0.MessageID == "") {
    test_passed++;
  }
  test_count++;

  if(test_msg_0.SentDateTime == "") {
    test_passed++;
  }
  test_count++;

  if(test_msg_0.MessageContentType == "") {
    test_passed++;
  }
  test_count++;

  if(test_msg_0.MessageDescription == "") {
    test_passed++;
  }
  test_count++;

  if(test_msg_0.OriginatingMessageID == "") {
    test_passed++;
  }
  test_count++;

  if(test_msg_0.inc_info.IncidentID == "") {
    test_passed++;
  }
  test_count++;

  if(test_msg_0.inc_info.IncidentDescription == "") {
    test_passed++;
  }
  test_count++;

  if(test_msg_0.msg_rcl.RecalledMessageID == "") {
    test_passed++;
  }
  test_count++;

  if(test_msg_0.msg_rcl.RecallType == "") {
    test_passed++;
  }
  test_count++;

  if(test_msg_0.fund.FundCode == "") {
    test_passed++;
  }
  test_count++;

  if(test_msg_0.fund.FundingInfo == "") {
    test_passed++;
  }
  test_count++;

  RequestResource test_msg_1("test_id");

  if(test_msg_1.MessageID == "test_id") {
    test_passed++;
  }
  test_count++;

}

int main() {
  u_request_resource();
  std::cout << "Passed " << (test_passed / test_count) * 100.0 << "% of " << int(test_count) << " tests\n";
}

