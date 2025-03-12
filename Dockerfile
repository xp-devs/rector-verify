FROM composer:latest as composer

FROM php:8.4-cli

RUN apt-get update && apt-get install -y \
    libzip-dev \
    && docker-php-ext-install zip

RUN pecl install xdebug \
    && docker-php-ext-enable xdebug

COPY --from=composer /usr/bin/composer /usr/local/bin/composer

RUN chmod +x /usr/local/bin/composer

WORKDIR /var/www

CMD ["tail", "-f", "/dev/null"]
