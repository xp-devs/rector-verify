<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;
use XpDevs\RectorVerify\AssertionVerifyRector;

return RectorConfig::configure()
    ->withRules([
        AssertionVerifyRector::class,
    ]);
