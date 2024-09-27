#include <ndn-cxx/face.hpp>
#include <ndn-cxx/security/key-chain.hpp>
#include <iostream>

int main()
{
  try {
    ndn::Face face;
    ndn::KeyChain keyChain;

    std::cout << "Registering prefix /example/testApp..." << std::endl;

    // Register the prefix with the forwarder
    face.registerPrefix(ndn::Name("/example/testApp"),
                        [](const ndn::Name& prefix) {
                          std::cout << "Prefix registered: " << prefix << std::endl;
                        },
                        [](const ndn::Name& prefix, const std::string& reason) {
                          std::cerr << "ERROR: Failed to register prefix: " << prefix
                                    << " Reason: " << reason << std::endl;
                        });

    std::cout << "Setting Interest Filter for /example/testApp..." << std::endl;

    // Set the interest filter (no need to register prefix again)
    face.setInterestFilter("/example/testApp",
                          [&face, &keyChain](const ndn::InterestFilter &filter, const ndn::Interest &interest) {
                            std::cout << "Received Interest: " << interest.getName() << std::endl;
                            // Handle the interest here, e.g., send back Data
                            ndn::Name dataName(interest.getName());
                            auto data = ndn::make_shared<ndn::Data>(dataName);
                            data->setFreshnessPeriod(ndn::time::seconds(10));
                            std::string content = "Hello, world!";
                            data->setContent(std::string_view(content));
                            keyChain.sign(*data);
                            face.put(*data);
                            std::cout << "Sent Data: " << *data << std::endl;
                          });

    std::cout << "Interest Filter Set!" << std::endl;

    // Keep the producer running
    while (true) {
      face.processEvents(ndn::time::milliseconds(100));
    }
  }
  catch (const std::exception &e) {
    std::cerr << "ERROR: " << e.what() << std::endl;
  }

  return 0;
}
