# Challenge 1 Brief

Produce a short video (2-3 mins) covering the following topics. You will need to research these – we will not tell you about them in great detail. That's a feature not a bug :-)

- [x] Embedded processors like the ESP32 underpin the Internet of Things (IoT)….
    - [x] What are the major challenges in the IoT?
    - [x] What are the big current markets for IoT technology?
- [x] Will IoT make a difference to society?
- [x] What are the ethical concerns with IoT technologies?
- [x] Show us the ESP32 working. For this:
    - [x] Write a program to output the current time on both the serial output of the TTGO T-display and also on its screen. Hint: you could connect to an NTP server using the WiFi connection in order to set the time on the device. You should feel free to use or combine any of the example programs for the ESP32 or TFT_eSPI so long as you say what you did.
    - [x] Demonstrate your program working, and explain (briefly!) what you did and how you did it.  
        This is a lot to fit into 3 minutes, so you will need to think carefully about what you include and how.

# Challenge 1 Research

## sources

[source 0](https://iot.ieee.org/articles-publications/newsletter/march-2017/three-major-challenges-facing-iot.html) IEEE  
[source 1](https://www.mckinsey.com/industries/semiconductors/our-insights/internet-of-things-opportunities-and-challenges-for-semiconductor-companies#/) McKinsey  
[source 2](https://www.forbes.com/sites/raufarif/2021/06/05/with-an-economic-potential-of-11-trillion-internet-of-things-is-here-to-revolutionize-global-economy/) Forbes  
[source 4](https://www.mckinsey.com/capabilities/mckinsey-digital/our-insights/the-internet-of-things-the-value-of-digitizing-the-physical-world) McKinsey  
[source 5](https://www.mckinsey.com/industries/semiconductors/our-insights/internet-of-things-opportunities-and-challenges-for-semiconductor-companies#/) McKinsey  
[source 6](https://www.sciencedirect.com/science/article/pii/S0148296321007906) ScienceDirect  
[source 7](https://www.grandviewresearch.com/industry-analysis/iot-market) Grandview Research  
[source 8](https://www.arduino.cc/education/societal-benefits-of-the-iot) Arduino  
[source 9](https://unesdoc.unesco.org/ark:/48223/pf0000387201/PDF/387201eng.pdf.multi) UNESCO  
[source 10](https://www.ibm.com/think/topics/internet-of-things) IBM

---

## definition

The internet of things (IoT) refer to a network of various physical objects embedded with sensors, software, and networking capabilities to collect, share and respond to data.

- smart thermostats, smart cars, industrial machinery, smart LED lights, wearables like smartwatches

---

## major challenges 

- Security
    - Hacking of baby monitors, smart fridges, thermo stats, drug infusion pumps, cameras, even car radio
    - each IoT device connected to the internet is an extra vector of attack for malicious actors
    - you are only as secure as your weakest link
    - sometimes this can be due to user negligence [example](https://www.bbc.co.uk/news/technology-51706631)
    - not every vendor ensures their IoT device is secure
- Connectivity
    - Network structures may need to be redesigned
    - Many IoT devices rely on the server-client model for authentication and connection between different network nodes
    - This star network model is sufficient for thousands of connected devices
    - But when networks grow to join billions or hundreds of billions of devices, a centralised system becomes a bottleneck
    - IoT has to become decentralised (check if it has, as source is old)
    - Moving tasks to the edge, using fog computing models
    - Some solutions include p2p but security becomes an issue
- Compatibility
    - Fast growth with many different and technologies competing to be the standard
    - Niche products resulting in a fragmented market with many application-specific chips that are unprofitable
    - Non-unified cloud services
    - Lack of standardised m2m (machine to machine) protocols
    - Diversity in firmware and OS of IoT devices
    - Some technologies become obsolete thus turning devices implementing them useless
- Longevity
    - Some devices remain in service for a long time, like smart fridges or TVs
    - Devices should be able to function even if their manufacturer goes out of service (movement of interest: [Stop Killing Games](https://www.stopkillinggames.com) )
- Standards
    - Network protocols, comms protocols and data-aggregation standards
    - Standard for handling unstructured data, NoSQL databases are diverse without a standard querying approach unlike structured data which uses SQL

---

## big current markets

- 2015 [Report 0](https://www.mckinsey.com/capabilities/mckinsey-digital/our-insights/the-internet-of-things-the-value-of-digitizing-the-physical-world) [Report 1](https://www.mckinsey.com/industries/semiconductors/our-insights/internet-of-things-opportunities-and-challenges-for-semiconductor-companies#/)
    - estimated to generate 4-11 trillion USD in value globally by 2025
    - estimated 7 billion to 10 billion connected devices, expected to reach 26 - 30 billion by 2020
- 2021 [Report 0](https://www.sciencedirect.com/science/article/pii/S0148296321007906) [Report 1](https://www.grandviewresearch.com/industry-analysis/iot-market)
    - approximately 24 billion connected devices in 2019
    - predicted to reach around 40 billion by 2025
    - valued at 1.18 trillion USD in 2023  
        expected 11.4% CAGR from 2024 to 2030
    - represented 36% of market revenue share in 2023 in the US

---

## make a difference to society

- we live in a smart city currently  
    [london is a smart city](https://www.grow.london/set-up-in-london/sectors/urban)
    
    - smart city technologies for [improved public transport](https://data.london.gov.uk/blog/improved-public-transport-for-london-thanks-to-big-data-and-the-internet-of-things/)
- enhances safety and security systems
    
    - allows quick response to time-critical situations, improving public safety
    - smart home security systems for remote monitoring and control
    - network of sensors/ smart city technologies detecting and responding to anomalous stimuli that may signal a natural disaster/ traffic congestion/ etc.
- improved efficiency
    
    - automate processes, connecting devices to process large amounts of data
    - increased efficiency in manufacturing, logistics and healthcare
- better convenience
    
    - remote control thermostats, lighting and security systems
- better healthcare
    
    - wearable devices to monitor vital signs, providing realtime data for healthcare professionals
- environmental benefits
    
    - optimising resource utilisation, reducing emissions
    - smart home technology may reduce energy usage such as by turning off lights when nobody is in the room etc.
- economic benefits
    
    - creation of new jobs and opportunities
    - economic growth through increased productivity
    - cost savings through improving supply chain management, reduction of downtime, optimisation of energy usage.

---

## ethical concerns

[unesco report](https://unesdoc.unesco.org/ark:/48223/pf0000387201/PDF/387201eng.pdf.multi)

- data misuse
- privacy concerns as data from sensors in devices can be reported back to companies
- data sold to brokers to create an even deeper profile on individuals that concerns to their physical lives as well as digital
- biases of algorithms and data analysis used in devices
    - may have implications on healthcare, education, policing etc.
- lack of security in devices may lead to potential vectors of attack for hackers

---