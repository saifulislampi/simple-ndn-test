#include <ndn-cxx/face.hpp>
#include <iostream>

int main()
{
  try {
    ndn::Face face;

    ndn::Name interestName("/example/testApp");
    ndn::Interest interest(interestName);
    interest.setCanBePrefix(false);
    interest.setMustBeFresh(true);

    std::cout << "Sending Interest: " << interest << std::endl;

    face.expressInterest(interest,
                         [](const auto&, const auto& data) {
                           std::cout << "Received Data: " << data << std::endl;
                           std::cout << "Content: " << std::string(reinterpret_cast<const char*>(data.getContent().value()), data.getContent().value_size()) << std::endl;
                         },
                         [](const auto&, const ndn::lp::Nack& nack) {
                           std::cout << "Received Nack: " << nack.getReason() << std::endl;
                         },
                         [](const auto& interest) {
                           std::cout << "Timeout for Interest: " << interest << std::endl;
                         });

    face.processEvents(ndn::time::seconds(5)); // Run for 5 seconds
  }
  catch (const std::exception& e) {
    std::cerr << "ERROR: " << e.what() << std::endl;
  }
  return 0;
}
