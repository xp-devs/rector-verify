<?php
declare(strict_types=1);

use XpDevs\RectorVerify\AssertionVerifyRector;
use Rector\Config\RectorConfig;

return RectorConfig::configure()
    ->withRules([
        AssertionVerifyRector::class,
    ]);
