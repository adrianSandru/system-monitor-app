#ifndef SYSTEMINFORMATION_H
#define SYSTEMINFORMATION_H


class SystemInformation
{
private:
    SystemInformation(const SystemInformation& systemInfo);
    SystemInformation& operator=(const SystemInformation& systemInfo);

protected:
    explicit SystemInformation();

public:

    static SystemInformation& instance();
    virtual ~SystemInformation();

    /**
     * @brief initialize
     * Allow to perform any initialization
     * needed depending on the OS specific platform
     */
    virtual void initialize()    = 0;

    /**
     * @brief cpuLoad
     * @return the average amount of cpu load
     */
    virtual double cpuLoad() = 0;

    virtual double cpuLoadInKernelMode() = 0;

    virtual double cpuLoadInUserMode() = 0;

    virtual double cpuLoadIdleMode() = 0;

    /**
     * @brief memoryUsage
     * @return the average amount of memory usage
     */
    virtual double memoryUsage() = 0;
};

#endif // SYSTEMINFORMATION_H
