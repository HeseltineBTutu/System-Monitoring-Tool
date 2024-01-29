# System Monitoring and Reporting Tool

## Overview

This project implements a system monitoring and reporting tool using Bash scripting for data collection and a C program for advanced processing and analytics.

## Table of Contents

1. [How to Run the System](#1-how-to-run-the-system)
2. [Customizing Analytics](#2-customizing-analytics)
3. [Configuring Alerting](#3-configuring-alerting)
4. [Setting up Email Alerts](#4-setting-up-email-alerts)

## 1. How to Run the System

### Prerequisites
- Ensure that you have the necessary permissions to read system data and execute scripts.
- The `system_data.txt` file should be present in the same directory as the executable.

Note:
Make sure the script has execute permissions (chmod +x script.sh) before running it. Additionally, it relies on system commands (df, top, free), so ensure those commands are available on your system.
### Execution
```bash
./system_analyzer
```

## 2. Customizing Analytics

The analytics logic is implemented in the `analyzer.c` file. To customize analytics:

- Open the `analyzer.c` file.
- Modify the `analyze_data` function to include additional conditions or calculations based on your requirements.
- Recompile the program after making changes:

```bash
gcc 0-main.c analyzer.c -o system_analyzer
```

## 3. Configuring Alerting

Integrate the Bash script and C program for alerting. Implement the alerting conditions and actions (email, log, console). Test the alerting mechanism with simulated scenarios.

```bash
# Example alerting configuration
./configure_alerts.sh
./system_analyzer
```

## 4. Setting up Email Alerts

If you wish to set up email alerts, follow these steps:

### Prerequisites
- Install a command-line email client such as `mail` or configure the system to send emails.
- Update the `trigger_alert` function in `analyzer.c` to include email sending logic.

#### Example with `mail` command
- Install the `mail` command if not already installed:
```bash
sudo apt-get install mailutils




